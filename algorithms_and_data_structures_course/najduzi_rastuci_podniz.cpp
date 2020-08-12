#include<bits/stdc++.h>
using namespace std;
int najduziRastuciPodniz(vector<int>& a) {
    int n=a.size();
    vector<int>dp(n);
    dp[0]=1;
    for(int i=1; i<n; i++) {
        dp[i]=1;
        for(int j=0; j<i; j++) {
            if(a[i]>a[j] && dp[j]+1>dp[i])
                dp[i]=dp[j]+1;
        }
    }
    int max=dp[0];
    for(int i=0; i<n; i++) {
        if(dp[i] > max)
        max=dp[i];
    }
    return max;
}
int main() {

    return 0;
}