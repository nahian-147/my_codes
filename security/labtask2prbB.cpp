#include<bits/stdc++.h>
#define ll  int64_t
#define pp pair<double,char>
#define ppn pair<pp,int>
#define F first
#define S second

using namespace std;



int main()
{

    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string plaintext = "IT CNJ FGM ETKMNOF CITMITK MIT JWF JIGFT GK YGK MINM SNMMTK CITMITK OM CNJ ZNB GK FOUIM IT CNJ NJINSTZ MG NJQ NDD MIT HDNFTM JTTSTZ MG DOXT RTFTNMI STMND MIT STND GY CIOEI IT INZ PWJM HNKMNQTF INZ RTTF DNRTDTZ DWFEITGF RWM MITKT CTKT SNFB HDNFTMJ CIOEI DOXTZ N JMNFZNKZ MOSTJENDT MINM MGGQ FG NEEGWFM GY MIT HTKINHJ OFEGFXTFOTFM NDMTKFNMOGF GY ZNB NFZ FOUIM. MIT KNMT GY HDNFTMNKB MWKFOFUJ ZOYYTKTZ, NFZ IT ZOZ FGM QFGC MINM GY MKNFMGK";


    string key = "QYWLCNOPHSRZTAIJKBMEGXUVFD";


    map<char,double>maps;



    int k = 9, l=0;
    for(int i=0; i<plaintext.length(); i++){

        if(plaintext[i]>='A' && plaintext[i]<='Z')
        {
            maps[plaintext[i]]++;
            l++;
        }

    }
    //Frequency
    vector<pp>v;
    for(int i=0; i<26; i++)
    {

        maps[s[i]]=(100.0*maps[s[i]])/l;

       v.push_back({maps[s[i]],s[i]});
    }
     sort(v.rbegin(),v.rend());



    for(int i=0; i<12; i++){
     cout<<fixed<<setprecision(2)<<v[i].S<<"  \t"<<v[i].F<<"%\t\t\t";
     cout<<fixed<<setprecision(2)<<v[i+13].S<<"  \t"<<v[i+13].F<<"%"<<endl;
    }

    cout<<"\n" << endl;
    ////Decyption
    for(int i=0; i<plaintext.length(); i++){
        if(plaintext[i]>='A' && plaintext[i]<='Z')
        {
            int x = plaintext[i]-'A';
            cout<<key[x];
        }
        else cout<<plaintext[i];

    }

}



