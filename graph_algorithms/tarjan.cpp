#include<bits/stdc++.h>
using namespace std;
struct Graph{
    int v;
    vector<vector<int>>adjacency_list;
    vector<int>lower_times;
    vector<int>times;
    int time;
    stack<int> stek;
    vector<bool>in_stek;
};
void init_graph(Graph& g, int v) {
    g.v=v;
    g.adjacency_list.resize(v);
    g.lower_times.resize(v,-1);
    g.times.resize(v,-1);
    g.time=0;
    g.in_stek.resize(v,false);
}
void add_edge(Graph& g, int u, int v) {
    g.adjacency_list[u].push_back(v);
}
void DFS(Graph& g, int u) {
    g.times[u]=g.lower_times[u]=g.time;
    g.time++;
    g.stek.push(u);
    g.in_stek[u]=true;
    auto begin=g.adjacency_list[u].begin();
    auto end=g.adjacency_list[u].end();

    while(begin!=end) {
        if(g.times[*begin]==-1) {
            DFS(g,*begin);

            g.lower_times[u]=min(g.lower_times[u], g.lower_times[*begin]);
        }
        else if(g.in_stek[*begin]==true) {
            g.lower_times[u]=min(g.lower_times[u], g.times[*begin]);
        }
        begin++;
    }
    if(g.times[u]==g.lower_times[u]) {
        
        while(1){
            int v=g.stek.top();
            g.stek.pop();
            cout<<v<<" ";
            g.in_stek[v]=false;
            if(v==u) {
                cout<<"\n";
                break;
            }

        }
    }
}

int main(){
    

  return 0;
}
