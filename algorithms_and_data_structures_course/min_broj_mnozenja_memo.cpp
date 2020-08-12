#include<bits/stdc++.h>
using namespace std;
int minBrojMNozenjaMemo(vector<int>& dimenzije, int l, int d, vector<vector<int>>& memo) {
    if(memo[l][d]!=-1) return memo[l][d];
    int n= d-l+1;
    if(n<=2) return 0;
    int min=numeric_limits<int>::max();
    for(int i=l+1; i<=d-1; i++) {
        int broj= minBrojMNozenjaMemo(dimenzije,l,i,memo) + minBrojMNozenjaMemo(dimenzije,i,d,memo) + dimenzije[l]*dimenzije[d]*dimenzije[i];
        if(broj<min) min=broj;
    }
    return memo[l][d]=min;
}
int main() {

    return 0;
}