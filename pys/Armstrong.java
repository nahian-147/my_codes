import java.lang.Math;

import javax.sound.sampled.SourceDataLine;

public class Armstrong{
    boolean isArmstrong(Integer n){
        String s = n.toString();
        int sum = 0;
        for(int i =0;i<s.length(); i++){
            int p = new Integer(s.charAt(i));
            sum += Math.pow(p, 3);
        }
        if(sum == n){
            return true;
        }else{
            return false;
        }
    }

    public static void main(String args[]){
        
        Armstrong a = new Armstrong();

        System.out.println(a.isArmstrong(153));
        System.out.println(a.numberOfSqures(3));
    }
    
    public int numberOfSqures(int n){
        int sum = 0;
        for (int k=1;k<=n;k++){
            sum += k*k;
        }
        return sum;
    }
}