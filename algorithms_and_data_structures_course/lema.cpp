#include<bits/stdc++.h>
using namespace std;
int LemaLemom(vector<int>&niz){
    
    sort(begin(niz),end(niz));
    int broj=0;
    for(int i=0;i<niz.size();i++){
        auto it = upper_bound(next(niz.begin(),i),niz.end(),niz[i]*niz[i]);
        if(it == niz.end())
            broj+=0;
        else{
            broj+=distance(it,niz.end());
        }
    
    }
    return broj;
    
}                 
int main() {

    return 0;
}