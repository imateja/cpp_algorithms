#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF=numeric_limits<int>::max();
struct Graph{
    int v;
    vector<vector<pii>>adjacency_list;
    vector<int>distances;
    vector<bool>path_found;
    vector<int>edges;
    vector<int>parents;
};
void init_graph(Graph& g, int v){
    g.v=v;
    g.adjacency_list.resize(v);
    g.distances.resize(v,INF);
    g.path_found.resize(v,false);
    g.edges.resize(v,INF);
    g.parents.resize(v,-1);
}
struct compare {
    bool operator()(const pii& p1, const pii& p2) {
        return p1.second > p2.second;
    }
};
void add_edge(Graph& g, int u, int v, int weight) {
    g.adjacency_list[u].push_back(make_pair(v,weight));
    g.adjacency_list[v].push_back(make_pair(u,weight));
}
void deconstruct(const pii& P, int& v, int& toV) {
    v=P.first;
    toV=P.second;
}
void dijkstra(Graph& g, int start, int v){
    priority_queue<pii,vector<pii>,compare>heap;
    g.distances[start]=0;
    g.edges[start]=0;
    heap.push(make_pair(start,g.distances[start]));
    int u, toU;
    while(!heap.empty()) {
        deconstruct(heap.top(), u, toU);
        heap.pop();
        if(g.path_found[u]) continue;
        g.path_found[u]=true;
        int v,toV;
        for(pii tmp : g.adjacency_list[u]) {
            deconstruct(tmp,v,toV);
            if(g.distances[v] > toU+toV || (g.distances[v]==toU+toV && g.edges[u]+1 < g.edges[v])) {
                g.distances[v]=toU+toV;
                g.edges[v]=g.edges[u]+1;
                g.parents[v]=u;
                heap.push(make_pair(v,g.distances[v]));
            }          
        }
       
    }
    stack<int>path;
    while(g.parents[v]!=-1) {
        path.push(v);
        v=g.parents[v];
    }
    path.push(v);
    while(!path.empty()) {
        cout<<path.top()<<" ";
        path.pop();
    }
    cout<<endl;
    
    }

int main() {
     

    return 0;
}
