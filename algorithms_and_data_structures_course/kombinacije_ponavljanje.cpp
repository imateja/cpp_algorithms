#include<bits/stdc++.h>
using namespace std;
void komb_ponavljanje(vector<int>& komb,int k, int i, int n_min, int n_max) {
    if(i==k) {
        ispisi(komb);
        return;
    }
    if(n_min>n_max)
        return;
    komb[i]=n_min;
    komb_ponavljanje(komb,k,i+1,n_min,n_max);
    komb_ponavljanje(komb,k,i,n_min+1,n_max);
}
int main() {

    return 0;
}