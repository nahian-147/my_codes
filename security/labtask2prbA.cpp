#include<bits/stdc++.h>

using namespace std;



int main()
{

    string scaninputs = "krclxrwrbxwnxocqnlxxunbcrwencrxwbrwanlnwccrvnb", s = "abcdefghijklmnopqrstuvwxyz", ans = "";

    int k = 9;
    for(int i=0; i<scaninputs.length(); i++){
     ans+=(((scaninputs[i]-'a')-9)+26)%26+'a';
    }
    cout<<ans<<endl;
}
