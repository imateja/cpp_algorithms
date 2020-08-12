#include<bits/stdc++.h>
using namespace std;
struct Graph{
    int v;
    vector<vector<int>>adjacency_list;
    vector<int>eulerian_path;
    stack<int>stek;
};
void init_graph(Graph& g, int v){
    g.v=v;
    g.adjacency_list.resize(v);
}
void add_edge(Graph& g, int u, int v) {
    g.adjacency_list[u].push_back(v);
}
void hierholzer(Graph& g, int start) {
    g.stek.push(start);
    int v=start;

    int tmp;
    while(!g.stek.empty()) {
        if(g.adjacency_list[v].size()) {
            g.stek.push(v);
            tmp=g.adjacency_list[v].back();
            g.adjacency_list[v].pop_back();
            v=tmp;
        }
        else {
            g.eulerian_path.push_back(v);
            v=g.stek.top();
            g.stek.pop();
        }
    }
    int i;
    for(i=g.eulerian_path.size() -1; i>=0; i--) {
        cout<<g.eulerian_path[i]<<" -> ";
    }
    cout<<endl;
}
int main() {
    

    return 0;   
}
