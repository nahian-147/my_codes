package smsclient;

import com.fasterxml.jackson.databind.ObjectMapper;

import java.io.IOException;
import java.util.Map;

public class Test {
    public static void main(String args[]) throws IOException {
        String postBody =
                    "{\"body\":{ \"SenderId\": \"REPLACE_FROM\", \"IsUnicode\": true, \"IsFlash\": true, \"MessageParameters\": [ { \"Number\": \"REPLACE_TO\", \"Text\": \"REPLACE_MESSAGE\" }], \"ApiKey\": \"Zkxpqqgggpm4Tq7gQw/uA0Y7U3B9XyKpMAWT/codkcU=\", \"ClientId\": \"02d5320e-5cfb-46ad-be6e-a0ac9f8fe406\" }}";
        ObjectMapper mapper = new ObjectMapper();
        Map postMap = mapper.readValue(postBody, Map.class);
        Map headerMap = (Map) postMap.get("header");

        String s = "";

        if (postBody.indexOf("header") > 0) {
            for (Object key : headerMap.keySet()) {
                s += (String) key + (String) headerMap.get(key);
            }
        }else{
            s = "Error";
        }
        System.out.println(s);
    }
}


package smsclient;

import com.fasterxml.jackson.databind.ObjectMapper;
import provider.ProviderDTO;
import provider.ProviderRepository;


import java.io.IOException;
import java.util.Map;

public class Test {
    public static void main(String args[]) throws IOException {
        ProviderDTO providerDTO = ProviderRepository.getInstance().getSMSProviderDTOByID(104);
        String postBody = providerDTO.getQueryURL();

        ObjectMapper mapper = new ObjectMapper();
        Map postMap = mapper.readValue(postBody, Map.class);
        Map headerMap = (Map) postMap.get("header");

        String s = "";

        if (postBody.indexOf("header") > 0) {
            for (Object key : headerMap.keySet()) {
                s += (String) key +":"+ (String) headerMap.get(key) + "\n";
            }
        }else{
            s = "Error";
        }
        System.out.println(s);
    }
}