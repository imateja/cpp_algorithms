#include<bits/stdc++.h>
using namespace std;
void binarne_varijacije(vector<int>& a, int n, int k, int i) {
    if(i==k) {
        ispisi(a);
        return;
    }
    else {
        for(int j=0; j<n; j++) {
            if((i-1)>=0 && a[i-1]==1 && j==1)
                continue;
            a[i]=j;
            binarne_varijacije(a,n,k,i+1);
        }
    }
}
int main() {
    return 0;
}