#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int INF=numeric_limits<int>::max();
struct Graph{
int v;
vector<vector<pii>>adjacency_list;
vector<int>dist;
vector<bool>found;

};
void init_graph(Graph& g, int v) {
    g.v=v;
    g.adjacency_list.resize(v);
    g.dist.resize(v,INF);
    g.found.resize(v,false);
    
}
void add_edge(Graph& g, int u, int v, int weight) {
    g.adjacency_list[u].push_back(make_pair(v,weight));
    g.adjacency_list[v].push_back(make_pair(u,weight));
}
struct compare{
    bool operator()(const pii& p1, const pii& p2) {
        return p1.second > p2.second;
    }
};
void deconstruct(const pii& P, int& v, int& toV){
    v=P.first;
    toV=P.second;
}
void dijkstra(Graph& g, int start) {
    priority_queue<pii, vector<pii>, compare>heap;
    int u, toU;
    g.dist[start]=0;
    heap.push(make_pair(start, g.dist[start]));
    while(!heap.empty()) {
        deconstruct(heap.top(), u, toU);
        heap.pop();
        if(g.found[u])
            continue;
        g.found[u]=true;

        int v, toV;
        for(pii tmp : g.adjacency_list[u]) {
            deconstruct(tmp, v, toV);
            if(toU + toV < g.dist[v]) {
                g.dist[v]=toU+toV;
                heap.push(make_pair(v, g.dist[v]));
            }
        }
        cout<<start<<"->"<<u<<": "<<g.dist[u]<<endl;

    }
}

int main() {
    
	
	return 0;
}
