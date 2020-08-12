#include<bits/stdc++.h>
using namespace std;
void zbirUzastopnih(vector<int>& brojevi, vector<int>& upiti) {
    for(int i=1; i<brojevi.size(); i++) {
        brojevi[i]+=brojevi[i-1];
    }

    for(int i=0; i<upiti.size(); i++) {
        auto it=lower_bound(brojevi.begin(), brojevi.end(),upiti[i]);
        if(it!=brojevi.end())
            cout<<distance(brojevi.begin(), it)+1<<endl;
        else cout<<-1<<endl;
        
    }
    cout<<endl;
}
int main() {

    return 0;
}