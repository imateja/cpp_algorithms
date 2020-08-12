#include<bits/stdc++.h>
using namespace std;
struct Graph{
    int v;
    vector<vector<int>>adjacency_list;
    vector<int>visited;
    vector<int>degrees;
};
void init_graph(Graph& g, int v){
    g.v=v;
    g.adjacency_list.resize(v);
    g.degrees.resize(v,0);
    g.visited.resize(v, false);
}
void add_edge(Graph&g, int u, int v) {
    g.adjacency_list[u].push_back(v);
    g.adjacency_list[v].push_back(u);
    g.degrees[u]++;
    g.degrees[v]++;
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
int count_odd_vertices(Graph& g){
    int counter=0;
    for(int i=0; i<g.v; i++){
        if(g.degrees[i] % 2)
        counter++;
    }
    return counter;
}
int find_even_node(Graph& g){
    for(int i=0; i<g.v; i++){
        if(g.degrees[i] % 2==0 && g.degrees[i])
        return i;
    }
}   
int find_odd_node(Graph&g){
    for(int i=0; i<g.v; i++){
        if(g.degrees[i] % 2)
        return i;
    }
}
void remove_edge(Graph& g, int u, int v){
    g.adjacency_list[u].erase(find(g.adjacency_list[u].begin(), g.adjacency_list[u].end(), v));
    g.adjacency_list[v].erase(find(g.adjacency_list[v].begin(), g.adjacency_list[v].end(), u));
}
bool is_valid_edge(Graph& g, int u, int v){
    if(g.adjacency_list[u].size()==1)
    return true;

    remove_edge(g,u,v);
    fill(g.visited.begin(), g.visited.end(), false);
    DFS(g,u);
    add_edge(g,u,v);

    if(!g.visited[v]) return false;
    return true;
}
void print_euler_path_or_cycle(Graph& g, int u){
    for(int v : g.adjacency_list[u]){
        if(is_valid_edge(g,u,v)){
            cout<<u<<" -> "<<v<<endl;
            remove_edge(g,u,v);
            print_euler_path_or_cycle(g,v);

            break;
        }
    }
}
void fleury(Graph&g){
    int node;
    int count_odd=count_odd_vertices(g);
    if(count_odd==0) {
        node=find_even_node(g);
        print_euler_path_or_cycle(g,node);
    }
    else if(count_odd==2){
        node=find_odd_node(g);
        print_euler_path_or_cycle(g,node);
    }
}
int main(){
    
    
    return 0;
}
