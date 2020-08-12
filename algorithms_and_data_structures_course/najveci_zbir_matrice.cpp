#include<bits/stdc++.h>
using namespace std;
int najveciZbirMatriceDesnoDOle(vector<vector<int>>& matrix, int n, int v, int k) {
    if(v==n-1 && k==n-1) return matrix[v][k];
    int dole, desno;
    if(v < n-1) dole=matrix[v][k] + najveciZbirMatriceDesnoDOle(matrix,n,v+1,k);
    if(k < n-1) desno=matrix[v][k] + najveciZbirMatriceDesnoDOle(matrix, n, v, k+1);
    if(v==n-1) return desno;
    if(k==n-1) return dole;
    return max(dole,desno);
}
int main() {

    return 0;
}