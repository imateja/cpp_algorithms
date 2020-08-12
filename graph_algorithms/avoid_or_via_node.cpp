#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int INF=numeric_limits<int>::max();
struct Graph{
    int v;
    vector<vector<pii>>adjacency_list;
    vector<int>distances;
    vector<bool>path_found;
};
struct comparator{
    bool operator()(const pii& p1, const pii& p2){
        return p1.second > p2.second;
    }
};
void init_graph(Graph& g, int v){
    g.v=v;
    g.adjacency_list.resize(v);
    g.distances.resize(v,INF);
    g.path_found.resize(v,false);
}
void add_edge(Graph& g, int u, int v, int weight){
    g.adjacency_list[u].push_back(make_pair(v,weight));
    g.adjacency_list[v].push_back(make_pair(u,weight));
}
void deconstruct(const pii& P, int& v, int& toV){
    v=P.first;
    toV=P.second;
}
int dijkstra(Graph& g, int start, int finish, int avoid){
    priority_queue<pii, vector<pii>, comparator>heap;

    int u,toU;
    g.distances[start]=0;
    heap.push(make_pair(start, g.distances[start]));
    while(!heap.empty()){
        deconstruct(heap.top(), u,toU);
        heap.pop();

        if(g.path_found[u]) continue;

        g.path_found[u]=true;
        int v,toV;
        for(pii tmp : g.adjacency_list[u]){
            deconstruct(tmp,v,toV);
            if(v==avoid) continue;
            if(toU+toV < g.distances[v]) {
                g.distances[v]=toU+toV;
                heap.push(make_pair(v,g.distances[v]));
            }
        }
    }
    return g.distances[finish];
}
void reset_graph(Graph& g){
    std::fill(g.distances.begin(), g.distances.end(), INF);
  std::fill(g.path_found.begin(), g.path_found.end(), false);
}
int shortest_path_via_node(Graph& g, int u, int v, int middle){
    int result=dijkstra(g,u,middle,-1);
    reset_graph(g);
    return result+dijkstra(g,middle,v,-1);
}
int shortest_path_avoid(Graph& g, int u, int v, int avoid){
    return dijkstra(g,u,v,avoid);
}

int main(){
    

    return 0;
}
