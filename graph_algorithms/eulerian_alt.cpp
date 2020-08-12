#include<bits/stdc++.h>
using namespace std;
struct Graph{
    int v;
    vector<vector<int>>adjacency_list;
    vector<bool>visited;
    vector<int>degrees;
};
void init_graph(Graph& g, int v){
    g.v=v;
    g.adjacency_list.resize(v);
    g.visited.resize(v, false);
    g.degrees.resize(v,0);
}
void add_edge(Graph& g, int u, int v){
    g.adjacency_list[u].push_back(v);
    g.adjacency_list[v].push_back(u);
    g.degrees[v]++;
    g.degrees[u]++;
}
int count_odd_degrees(Graph& g){
    int counter=0;
    for(int i=0; i<g.v; i++){
        if(g.degrees[i] % 2)
        counter++;
    }
    return counter;
}
void DFS(Graph& g, int u){
    g.visited[u]=true;
    auto begin=g.adjacency_list[u].begin();
    auto end=g.adjacency_list[u].end();
    while(begin!=end){
        if(!g.visited[*begin])
        DFS(g,*begin);

        begin++;
    }
}
bool is_connected(Graph& g){
    int start_node;
    for(int i=0; i<g.v; i++){
        if(g.degrees[i] > 0)
        start_node=i;
    }
    DFS(g,start_node);

    for(int i=0; i<g.v; i++){
        if(g.degrees[i] > 0 && g.visited[i]==false)
            return false;
    }
    return true;
}
bool is_eulerian(Graph& g){
    if(count_odd_degrees(g) > 2) return false;
    if(is_connected(g)==false) return false;

    return true;
}
int main(){
    
    
    return 0;
}
