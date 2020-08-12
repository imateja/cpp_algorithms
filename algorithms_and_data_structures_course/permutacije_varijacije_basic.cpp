#include<bits/stdc++.h>
using namespace std;
void ispisi(vector<int>& a) {
    for(int i=0; i<a.size(); i++) {
        cout<< a[i]<< " ";
    }
    cout<<endl;
}   
void varijacije(vector<int>& a, int n, int k, int i) { //sa ponavljanjem
    if(i==k) {
        ispisi(a);
        return;
    }
    else {
        for(int j=1; j<n; j++) {
            a[i]=j;
            varijacije(a,n,k,i+1);
        }
    }
}
void permutacije(vector<int>& a, int n ,int i, vector<int>& exists) {
    if(i==n) {
        ispisi(a);
        return;
    }
    else {
        for(int j=1; j<=n; j++) {
            if(!exists[j-1]) {
                a[i]=j;
                exists[j-1]=1;
                permutacije(a,n,i+1,exists);
                exists[j-1]=0;
            }
        }
    }
}
int main() {

    return 0;
}