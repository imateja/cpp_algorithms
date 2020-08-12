#include<bits/stdc++.h>
using namespace std;
int najduzi_zajednicki_podniz(const string& s1, const string& s2) {
    int n1=s1.size(), n2=s2.size();
    vector<vector<int>>dp(n+1);

    for(int i=0; i<=n1; i++) {
        dp[i].resize(n2+1, 0);
    }
    for(int i=1; i<=n1; i++) {
        for(int j=1; j<=n2; j++) {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n1][n2];
}
int main() {

    return 0;
}