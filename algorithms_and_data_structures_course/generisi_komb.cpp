#include<bits/stdc++.h>
using namespace std;
void ispisi(vector<int>brojevi) {
    for(int i=0; i<brojevi.size(); i++) {
        cout<<brojevi[i]<<" ";
    }
    cout<<endl;
}
void generisi(vector<int>& temp, int duzina, int j, int opseg) {
    if(j==duzina) {
        ispisi(temp);
        return;
    }
    for(int i=1; i<=opseg; i++) {
        temp[j]=i;
        if(validan(temp, j))
            generisi(temp,duzina,j+1, opseg);

    }
}
int main() {
    return 0;
}