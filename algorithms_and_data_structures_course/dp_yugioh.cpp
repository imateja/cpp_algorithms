#include<bits/stdc++.h>
using namespace std;
int yugioh(string& s1, string& s2, int i, int j) {
    if(i<0 && j<0) return 0;
    if(i<0) return j;
    if(j<0) return i;


    if(s1[i]==s2[i]) return 1+yugioh(s1,s2,i-1, j-1);

    return min(yugioh(s1,s2,i,j-1) + 1, yugioh(s1,s2,i-1, j)+1);
}

int main() {

    return 0;
}