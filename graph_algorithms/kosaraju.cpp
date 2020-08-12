#include<bits/stdc++.h>
using namespace std;
struct Graph{
    int v;
    vector<vector<int>>adjacency_list;
    vector<bool>visited;
};
void add_edge(Graph&g, int u, int v){
    g.adjacency_list[u].push_back(v);
}
void init_graph(Graph& g, int v){
    g.v=v;
    g.adjacency_list.resize(v);
    g.visited.resize(v, false);
}
void DFS(Graph& g,int u){
    g.visited[u]=true;

    auto begin=g.adjacency_list[u].begin();
    auto end=g.adjacency_list[u].end();
    while(begin!=end){
        if(!g.visited[*begin])
            DFS(g,*begin);
        begin++;
    }
}
int count_unvisited_nodes(Graph& g){
    int counter=0;
    for(int i=0; i<g.v; i++){
        if(!g.visited[i]) counter++;

    }
    return counter;
}
Graph reverse_edges(Graph& g){
    Graph g_pom;
    init_graph(g_pom, g.v);

    for(int i=0; i<g.v; i++){
        for(int u : g.adjacency_list[i])
        add_edge(g_pom, u, i);
    }
    return g_pom;
}
bool kosaraju(Graph& g){
    DFS(g,0);
    if(count_unvisited_nodes(g) > 0) return false;
    Graph g_pom=reverse_edges(g);
    DFS(g_pom,0);
    if(count_unvisited_nodes(g_pom) > 0) return false;

    return true;
}
int main(){
    

    return 0;
}
