#include<bits/stdc++.h>
using namespace std;
int brojMentora(vector<int>& rejting, vector<bool>& jeMentor) {
    int n=rejting.size();
    jeMentor.resize(n,false);
    sort(rejting.begin(),rejting.end());
    int mentor=1;
    int brojParova=0;

    for(int ucenik=0; mentor<n; ucenik++) {
        while(mentor<n) {
            if(!jeMentor[mentor] && rejting[mentor]>=2*rejting[ucenik]) {
                brojParova++;
                jeMentor[mentor]=true;
                break;
            }
            else {
                mentor++;
            }
        }
    }
return brojParova;
}
int main() {
    return 0;
}