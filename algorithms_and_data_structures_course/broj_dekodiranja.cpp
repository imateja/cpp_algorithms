#include<bits/stdc++.h>
using namespace std;
long long broj_dekodiranja(const string& s) {
    if(s=="")
    return 1;

    long long rez=0;
    if(s[0]!='0')
    rez+=broj_dekodiranja(s.substr(1));

    if(s.length()>=2 && s[0]!='0' && 10*(s[0]-'0')+s[1]-'0'<=26)
    rez+=broj_dekodiranja(s.substr(2))

    return rez;
}
int main() {

    return 0;
}