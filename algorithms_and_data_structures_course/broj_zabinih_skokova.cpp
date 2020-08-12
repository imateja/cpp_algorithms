#include<bits/stdc++.h>
using namespace std;
int brojZabinihSkokova(vector<int>& kamenje, int r) {
    int n=kamenje.size();
    int broj=0; 
    int kamen=0;

    while(kamen < n-1) {
        int noviKamen=kamen;
        while(noviKamen+1 <n && kamenje[noviKamen+1]-kamenje[kamen]<=r) {
            noviKamen++;
        }
        if(noviKamen==kamen) return n; //simbolika da ne moze da skoci nigde
        broj++;
        kamen=noviKamen;
    }
    return broj;
}
int main() {

    return 0;
}