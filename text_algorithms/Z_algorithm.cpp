#include<bits/stdc++.h>
using namespace std;
vector<int>Zalgorithm(string& niska){
    int n=niska.size();
    int l=0, d=0;
    vector<int>z(n);
    for(int i=1; i<n; i++){
        if(i<=d)
        z[i]=min(d-i+1, z[i-l]);

        while(i+z[i] < n && niska[z[i]]==niska[i+z[i]])
            z[i]++;
        if(i+z[i] -1 > d) {
            l=i;
            d=i+z[i]-1;
        }
    }
    return z;
}
int main(){

    return 0;
}
