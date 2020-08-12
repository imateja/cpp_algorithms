#include<bits/stdc++.h>
using namespace std;
struct Graph {
    int v;
    vector<vector<int>>adjacency_list;
    vector<bool>visited;
    int num_of_cycles;
};
void init_graph(Graph& g, int v) {
    g.v=v;
    g.visited.resize(v,false);
    g.adjacency_list.resize(v);
    g.num_of_cycles=0;
}
void add_edge(Graph& g, int u, int v) {
    g.adjacency_list[u].push_back(v);
    g.adjacency_list[v].push_back(u);
}
void DFS(Graph& g, int u, int n, int start) {
        g.visited[u]=true;
    if(n==0) {  
        if(find(g.adjacency_list[u].begin(), g.adjacency_list[u].end(), start)!=g.adjacency_list[u].end()) {
            g.num_of_cycles++;
        }
        g.visited[u]=false;
            return;
    }

    auto begin=g.adjacency_list[u].begin();
    auto end=g.adjacency_list[u].end();

    while(begin!=end) {
        if(!g.visited[*begin])
            DFS(g,*begin,n-1, start);
        begin++;
    }
    g.visited[u]=false;
}
int count_cycles(Graph& g, int n) {
    for(int i=0; i<g.v; i++) {
        DFS(g,i,n-1,i);
        g.visited[i]=true;
    }
    return g.num_of_cycles/2;
}
int main() {
    


    return 0;
}
