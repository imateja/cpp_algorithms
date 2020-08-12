#include<bits/stdc++.h>
using namespace std;
double problemRancaMaxCena(vector<int>& mase, vector<double>& cene, double nosivost, int n) {
    if(n==0) return 0.0;
    double cenaBez= problemRancaMaxCena(mase,cene,nosivost,n-1);
    if(m[n-1] > nosivost) return cenaBez;
    double cenaSa= problemRancaMaxCena(mase,cene,nosivost-mase[n-1], n-1) + cene[n-1];
    return max(cenaBez,cenaSa);
}
int main() {

    return 0;
}