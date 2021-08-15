#include<bits/stdc++.h>
#define ll long long


using namespace std;

int main()
{

    int k;
    cout<<"Type '1' for encryption, Type '2' for Decryption:";
    cin>>k;

    string s = "abcdefghijklmnopqrstuvwxyz", s1="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char k1[200];



    string key;
    cout<<"Enter your Key:\n";
    cin>>key;
    // for encryption
    cout<<"In here Enter Your Text (Write \"-5\" to See Output):\n";

    string plaintext="",x;
    while((cin>>x)&&x!="-5"){
      plaintext+=x+" ";
    }

    int j=0, l;
    l = key.length();
// for encryption
   if(k==1){
    for(int i=0; i<plaintext.length(); i++){
          if(j==l) j=0;
        if(plaintext[i]>='A' && plaintext[i]<='Z')
        {
            int x = ((plaintext[i]-'A') + (key[j]-'a'))%26;
            cout<<s[x];
            j++;
        }
        else if(plaintext[i]>='a' && plaintext[i]<='z')
        {
            int x = ((plaintext[i]-'a') + (key[j]-'a'))%26;
            cout<<s[x];
            j++;
        }
        else cout<<plaintext[i];

    }

    }

//for decryption
    else{
    for(int i=0; i<plaintext.length(); i++){
          if(j==l) j=0;

        if(plaintext[i]>='a' && plaintext[i]<='z')
        {
            int x = ((plaintext[i]-'a') - (key[j]-'a')+26)%26;

            if(i==0){
                cout<<s1[x];
            }
            else cout<<s[x];
            j++;
        }
        else cout<<plaintext[i];

    }
    }


}
