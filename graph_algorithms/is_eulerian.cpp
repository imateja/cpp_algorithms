#include<bits/stdc++.h>
using namespace std;
struct Graph {
    int v;
    vector<vector<int>>adjacency_list;
    vector<int>in_degrees;
    vector<bool>visited;
};
void init_graph(Graph& g, int v) {
    g.v=v;
    g.visited.resize(v,false);
    g.in_degrees.resize(v,0);
    g.adjacency_list.resize(v);
}
void add_edge(Graph& g, int u, int v) {
    g.adjacency_list[u].push_back(v);
    g.in_degrees[v]++;
}
void DFS(Graph& g, int u) {
    g.visited[u]=true;
    auto begin=g.adjacency_list[u].begin();
    auto end=g.adjacency_list[u].end();

    while(begin!=end) {
        if(!g.visited[*begin])
            DFS(g,*begin);
        begin++;
    }
}
Graph reverse_edges(Graph& g) {
    Graph g_pom;
    init_graph(g_pom, g.v);
    for(int i=0; i<g.v; i++) {
        for(int u : g.adjacency_list[i]) {
            add_edge(g_pom, u,i);
        }
    }
    return g_pom;
}
int count_unvisited_nodes(Graph& g) {
    int counter=0;
    for(int i=0; i<g.v; i++) {
        if(g.visited[i]==false && (g.in_degrees[i] > 0 || g.adjacency_list[i].size() > 0)) counter++;
    }
    return counter;
}
bool kosaraju(Graph& g){
    Graph g_pom=reverse_edges(g);
    int node;
    for(int i=0; i<g.v; i++) {
        if(g.adjacency_list[i].size() > 0) {
        node=i;
        break;
        }
    }
    DFS(g,node);
    if(count_unvisited_nodes(g) > 0) return false;
    DFS(g_pom, node);
    if(count_unvisited_nodes(g_pom) > 0) return false;
    return true;
}
bool is_eulerian(Graph& g) {
    if(kosaraju(g)==false) return false;
    for(int i=0; i<g.v; i++) {
        if(g.in_degrees[i]!=g.adjacency_list[i].size()) return false;
    }
    return true;
}
int main() {
     
    return 0;
}
