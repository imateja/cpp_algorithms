#include<bits/stdc++.h>
using namespace std;
int najmanji_broj_novcica(vector<int>& novcici, int iznos) {
    int N=novcici.size(), M=iznos;
    vector<vector<int>>dp(N+1);
    for(int i=0; i<=novcici.size(); i++) {
        dp[i].resize(M+1);
    }
    dp[0][0]=0;
    for(int i=1; i<=M; i++)
    dp[0][i]=INFINITY;
    for(int i=1; i<=N; i++) {
    dp[i][0]=0;
    for(int iznos=1; iznos<=M; iznos++) {
        dp[i][iznos]=dp[i-1][iznos];
        if(novcici[i-1]<= iznos && dp[i-1][iznos-novcici[i-1]]!=INFINITY)
        dp[i][iznos]=min(dp[i][iznos], 1 + dp[i-1][iznos- novcici[i-1]]);
    }
    }
    return dp[N][M];
}
int main() {

    return 0;
}