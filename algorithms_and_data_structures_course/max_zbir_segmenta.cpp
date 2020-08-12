#include<bits/stdc++.h>
using namespace std;
int maxZbirSegmenta(vector<int>& niz) {
    int n=niz.size();
    vector<int>dp(n+1);
    dp[0]=0;

    for(int i=1; i<=n;i++) {
        dp[i]=max(0, dp[i-1]-niz[i-1]);
    }
    int rez=dp[0];
    for(int i=1; i<=n; i++) {
        rez=max(rez,dp[i]);
    }
    return rez;
}
int main() {

    return 0;
}