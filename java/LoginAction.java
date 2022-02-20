package login;

import billingactivity.BillingActivityConstants;
import billingactivity.BillingActivityManager;
import client.ClientDTO;
import client.ClientRepository;
import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.radius.utils.RadiusConfiguration;
import com.radius.utils.RadiusConfigurationConstants;
import com.sun.org.slf4j.internal.LoggerFactory;
import ipmanagement.BlackAndWhiteListIpRepository;
import org.apache.commons.lang3.StringUtils;
import org.apache.log4j.Logger;
import org.apache.log4j.PropertyConfigurator;
import org.apache.struts.action.Action;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;

//import rateplan.DRPFileUploadFromEmail;
//import rateplan.DestinationRatePlanExpirationHandler;
//import rateplan.DestinationRatePlanFileUploadHandler;
import sessionmanager.SessionManager;
import user.UserDTO;
import user.UserRepository;
import util.*;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.File;
import java.util.HashMap;

public class LoginAction extends Action {
    static Logger logger = Logger.getLogger(LoginAction.class);
    private static boolean initializeStatus = false;

//    static {
//        DestinationRatePlanExpirationHandler.getInstance();
//        // (new Thread(new DestinationRatePlanExpirationHandler())).start();
//        DestinationRatePlanFileUploadHandler.getInstance();
//        logger.debug("PaymentDescriptionUtil.updateRateFromEmail = " + PaymentDescriptionUtil.updateRateFromEmail);
//        if(PaymentDescriptionUtil.updateRateFromEmail) {
//            DRPFileUploadFromEmail.getInstance();
//        }
//    }

    public synchronized void initializeBilling (HttpServletRequest p_request) {
        try {
            if (!initializeStatus) {
                // PropertyConfigurator.configure("log4j.properties");

                String realContextPath = p_request.getSession().getServletContext().getRealPath("");

                File[] downloadFiles = (new File(realContextPath, "monitoring")).listFiles();
                if (downloadFiles != null) {
                    for (File reportFile : downloadFiles) {
                        if (reportFile.getName().endsWith(".zip")) {
                            boolean isDeleted = reportFile.delete();
                        }
                    }
                }

                downloadFiles = (new File(realContextPath, "billgeneration")).listFiles();
                if (downloadFiles != null) {
                    for (File billFile : downloadFiles) {
                        if (billFile.getName().endsWith(".csv")) {
                            boolean isDeleted = billFile.delete();
                        }
                    }
                }

                downloadFiles = (new File(realContextPath, "rateplan")).listFiles();
                if (downloadFiles != null) {
                    for (File ratePlanFile : downloadFiles) {
                        if (ratePlanFile.getName().endsWith(".csv")) {
                            boolean isDeleted = ratePlanFile.delete();
                        }
                    }
                }

                initializeStatus = true;
            }

        } catch (Exception e) {
            logger.debug("Exception deleting generated download files", e);
        }
    }

    public ActionForward execute(ActionMapping p_mapping,
            ActionForm p_form,
            HttpServletRequest p_request,
            HttpServletResponse p_response) {
        if (!initializeStatus) {
            initializeBilling(p_request);
        }
        String target = "home";

        String mailPass = p_request.getParameter("mailPassword");
        if ((mailPass != null) && (mailPass.equals("1"))) {
            logger.debug("Value of mailPassword:" + mailPass);
            target = "mailPassword";
            return p_mapping.findForward(target);
        }
        LoginForm form = (LoginForm) p_form;
        LoginService service = new LoginService();
        LoginDTO dto = new LoginDTO();

        String token = p_request.getParameter("token");
        logger.debug("Token = "+token);
        if (ConfigurationConstants.isSSOEnabled ) {
            if (StringUtils.isNotEmpty(token)) {
                try {
                    token = AES.decrypt(token);
                    logger.debug("Decrypted Token = "+token);

                    String[] parts = token.split("\\.");
                    ObjectMapper mapper = new ObjectMapper();
                    HashMap<String, String> params = mapper.readValue(parts[1], new TypeReference<HashMap<String, String>>() {
                    });

                    form.setUsername(params.get("subject"));
                    form.setPassword("");
                    form.setLoginURL(ConfigurationConstants.ssoUrl
                            .substring(ConfigurationConstants.ssoUrl.indexOf("?")));

                }catch (Exception e) {
                    logger.debug("Exception", e);
                }
            } else {
                logger.debug("Invalid login. token not received.");
                return p_mapping.findForward("actionError");
            }
        }

        dto.setLoginSourceIP(p_request.getRemoteAddr());
        dto.loginPort = p_request.getRemotePort();

        dto.setUsername(form.getUsername());
        dto.setPassword(form.getPassword());
        dto.setLoginURL(form.getLoginURL());

        String languageID = p_request.getParameter("language");
        if (languageID == null) {
            languageID = "1";
        }
        dto.setLanguageID(Integer.parseInt(languageID));
        String webRoot = p_request.getParameter("web_root");
        if (webRoot != null) {
            dto.setWebRoot(webRoot);
        }
        String genericPage = p_request.getParameter("generic_page");
        if (genericPage != null) {
            dto.setGenericPage(genericPage);
        }
        try {
            /* String rqURL = "";
            rqURL = p_request.getParameter("urlRefer");

            if (p_request.getSession() != null || p_request.isRequestedSessionIdValid()) {
                if (p_request.getSession().getAttribute("referal") == null) {
                    if (rqURL != null && !rqURL.equals("null")) {
                        p_request.getSession(true).setAttribute("referal",rqURL );
                    }
                }
            }*/

            boolean isBlackList = BlackAndWhiteListIpRepository.getInstance().isBlackListedIP(dto.getLoginSourceIP());
            if (isBlackList) {
                logger.debug("Got Login Request from Black Listed ip:" + dto.getLoginSourceIP());

                service.logUnAuthorizeRequest(dto.getLoginSourceIP(), dto.getUsername());
                target = "actionError";

                p_request.getSession().setAttribute("loginFailure",
                        iTelBillingProperties.getInstance().getValue("error.loginblocked"));
            } else {
                dto = service.validateUser(dto);

                int useOTPToken = 0;
                try {
                    useOTPToken = Integer.parseInt(RadiusConfiguration.getInstance().getConfigurationValue(RadiusConfigurationConstants.ENABLE_OTP_TOKEN));
                    logger.debug("useOTPTokenVal: " + useOTPToken);
                } catch (Exception ignored) {
                }
                if (dto == null) {
                    logger.debug("Invalid Login");

                    if (webRoot != null) {
                        target = "web_root";
                        p_request.getSession(true).setAttribute("web_root", webRoot);
                    } else {
                        target = "actionError";
                    }

                    UserDTO userDTO = UserRepository.getInstance().getUserByUserName(form.getUsername());
                    if (userDTO != null) {
                        logger.debug("Retry time left is: " + userDTO.retryTimeLeft);
                        p_request.getSession(true).setAttribute("retryLeft", userDTO.retryTimeLeft);
                        p_request.getSession(true).setAttribute("userStatus", userDTO.getStatus());
                        logger.debug("current val in session: " + p_request.getSession(true).getAttribute("retryLeft"));
                        logger.debug("value of status: " + p_request.getSession(true).getAttribute("userStatus"));
                        logger.debug("came with error 1");
                    } else {
                        logger.debug("user dto: null");
                    }

                    p_request.getSession().setAttribute("loginFailure",
                            iTelBillingProperties.getInstance().getValue("error.loginfailure"));
                    logger.debug("came with error 2");
                    BillingActivityManager.getInstance().addBillingActivityLog(BillingActivityConstants.ACTION_INVALID_LOGIN,
                            BillingActivityConstants.LOGIN_MODULE,
                            form.getUsername(), form.getUsername(),
                            System.currentTimeMillis(), "Login Failed",
                            p_request.getRemoteAddr());
                    logger.debug("came with error 3");

                    try {
                        Thread.sleep(5000L);
                    } catch (Exception ignored) {

                    }
                } else {
                    logger.debug("Login credentials Accepted");
                    logger.debug("get OTP serial :" + dto.getOTPSerial());

                    UserDTO userDTO = UserRepository.getInstance().getUserByUserName(dto.getUsername());
                    int otpGenerationType = -1;
                    if (userDTO != null) {
                        otpGenerationType = userDTO.getOtpGenerationType();
                    } else {
                        ClientDTO clientDTO = ClientRepository.getInstance().getClient(dto.getUsername());
                        if (clientDTO != null) {
                            otpGenerationType = clientDTO.getOtpGenerationType();
                        }
                    }

                    String loginMsg = "Login Successful";
                    if (useOTPToken == 1 && otpGenerationType > 0) {
                        target = "getSoftOTPToken";
                        loginMsg = "OTP Requested";
                        HttpSession session = p_request.getSession(true);
                        session.setAttribute("user_otp_token", dto);

                        if (((otpGenerationType & OTPUtil.OTP_VIA_EMAIL) == OTPUtil.OTP_VIA_EMAIL
                                || (otpGenerationType & OTPUtil.OTP_VIA_SMS) == OTPUtil.OTP_VIA_SMS)
                                && !(new OTPUtil()).sendOTP(dto)) {
                            SessionManager.setFailureMessage(p_request, "Failed to send otp via selected option.");
                            target = "failure";
                        }

                        if (dto.getOTPSerial() != null) {
                            logger.debug("User have Token");
                        }

                    } else if ((BadUserNameRepository.getInstance().isBadUserName(dto.getUsername()))
                            || (dto.getpasswordExpirationType() == 1)
                            || ((dto.getpasswordExpirationType() == 2) && (dto.getpasswordExpirationTime() <= System.currentTimeMillis()))) {
                        target = "changePassword";
                        loginMsg = "New Password Requested";
                        p_request.getSession(true).setAttribute("user_password_change", dto);
                    } else {
                        p_request.getSession(true).setAttribute("user_login", dto);
                        LoginSessionManager.getInstance().saveLoginSession(p_request.getSession(true).getId(), dto);
                    }

                    BillingActivityManager.getInstance()
                            .addBillingActivityLog(BillingActivityConstants.ACTION_VALID_LOGIN,
                                    BillingActivityConstants.LOGIN_MODULE,
                                    form.getUsername(), form.getUsername(),
                                    System.currentTimeMillis(), loginMsg,
                                    p_request.getRemoteAddr());
                }
            }
            logger.debug("Remote Address :" + p_request.getRemoteAddr());

        } catch (Exception e) {
            logger.error("Exception during login", e);
            target = "failure";
            SessionManager.setFailureMessage(p_request, e.toString());
        }

        if (dto != null && dto.getAccountID() > 0 && target.equals("home")) {
            target = "client";
        }
        return p_mapping.findForward(target);
    }
}
