#include<bits/stdc++.h>
using namespace std;
using namespace std;
int brojTrouglova(vector<int>& duzine, int i, int j, int k) { // u mejnu se poziva sa (duzine,0,1,n-1)
    sort(duzine.begin(), duzine.end());
    int brojTrouglova=0;
    int it=0;
    while(k>1) {
        it++;
        int a=duzine[i]*duzine[i];
        int b=duzine[j]*duzine[j];
        int c=duzine[k]*duzine[k];
        if(a+b==c) {
            brojTrouglova++;
        }
        if(i==k-1) {
            i=0;
            j=1;
            k--;
        }
        else if(j==k-1) {
            i++;
            j=i+1;  
        }
        else if(j!=k-1) {
            j++;
        }
    }
    return brojTrouglova;
}
int main() {
    return 0;
}