#include<bits/stdc++.h>
using namespace std;
int brojParova(vector<int>& decaci, vector<int>& devojke, int n, int t) {
    sort(decaci.begin(), decaci.end(), greater<int>());
    sort(devojke.begin(), devojke.end());
    int m=0, d=0;
    int brojParova=0;
    while(m<n && d<n) {
        if(decaci[m]+devojke[d]>=t) {
            m++;
            brojParova++;
            d++;
        }
        else {
            d++;
        }
    }
    return brojParova;
}

int main() {

    return 0;
}