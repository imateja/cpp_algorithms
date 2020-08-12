#include<bits/stdc++.h>
using namespace std;
void sledeciOpadajuciNiz(vector<int>& niz,int n) {
    if(niz[n-1]==n) {
        cout<<"Nema!"<<endl;
        return;
    }
    for(int i=n-1;i>=0; i--) {
        niz[i]++;
        if(niz[i-1]>=niz[i]) break;
        else niz[i]=1;
    }
    for(int i=0; i<n; i++) cout<<niz[i]<<" ";
    cout<<endl;
}
int main() {
    return 0;
    }