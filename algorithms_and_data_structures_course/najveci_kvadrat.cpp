#include<bits/stdc++.h>
using namespace std;
int najveciKvadrat(int A[MAX][MAX], int m, int n) {
    int dp[MAX][MAX];
    for(int i=0; i<m; i++) {
        dp[i][0]=A[i][0];
    }
    for(int j=0; j<n; j++) {
        dp[0][j]=A[0][j];
    }
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            if(A[i][j]==0)
            dp[i][j]=0;
            else
            dp[i][j]=min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]})+1;
        }
    }
    int max=0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(dp[i][j] > max)
            max=dp[i][j];
        }
    }
    return max;
}
int main() {

    return 0;
}