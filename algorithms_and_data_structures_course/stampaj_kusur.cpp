#include<bits/stdc++.h>
using namespace std;
void stampajKusur(int iznos) {
    vector<int>apoeni={500,200,100,50,20,10,5,2,1};
    while(iznos>0) {
        for(int apoen: apoeni) {
            if(iznos>=apoen)
            cout<<apoen<<" ";
        }
    }
    cout<<endl;
}
int main() {

    return 0;
}