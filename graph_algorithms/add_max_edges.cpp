#include<bits/stdc++.h>
using namespace std;
struct Graph{
    int v;
    vector<vector<int>>adjacency_list;
    vector<bool>visited;
    vector<int>in_degrees;
    vector<pair<int,int>>undirected_edges;
    vector<int>position_in_top_sorting;
    vector<pair<int,int>>edges;
    vector<pair<int,int>>added_edges;
    
};
void initialize_graph(Graph& g, int v) {
    g.v=v;
    g.adjacency_list.resize(v);
    g.visited.resize(v,false);
    g.in_degrees.resize(v,0);
    g.position_in_top_sorting.resize(v);
}
void add_directed_edge(Graph& g, int u, int v) {
    g.adjacency_list[u].push_back(v);
    g.in_degrees[v]++;
    pair<int,int>p(u,v);
    g.edges.push_back(p);
}
void add_undirected_edge(Graph& g, int u, int v) {
    pair<int,int>p(u,v);
    g.undirected_edges.push_back(p);
}
void topological_sorting(Graph& g) {
    queue<int>nodes;

    int tmp;
    for(int i=0; i<g.v; i++) {
        if(!g.in_degrees[i])
        nodes.push(i);
    }

    while(!nodes.empty()) {
        tmp=nodes.front();
        nodes.pop();
        g.position_in_top_sorting.push_back(tmp);
        for(int node: g.adjacency_list[tmp]) {
            g.in_degrees[node]--;
            if(!g.in_degrees[node])
                nodes.push(node);
        }   
    }
}
void add_max_edges(Graph& g) {
    topological_sorting(g);
    for(int i=0; i<g.v; i++) {
        for(int y : g.adjacency_list[g.position_in_top_sorting[i]])
            g.visited[y]=true;
        
        for(int j=i+1; j<g.v;j++) {
            if(!g.visited[g.position_in_top_sorting[j]]) {
                pair<int,int>p(g.position_in_top_sorting[i], g.position_in_top_sorting[j]);
                g.added_edges.push_back(p);
                g.edges.push_back(p);
            }
            g.visited[g.position_in_top_sorting[j]]=false;
        }
    }
}
int main() {

    return 0;
}