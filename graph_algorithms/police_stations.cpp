#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int INF=numeric_limits<int>::max();
struct comparator{
    bool operator()(const pii& p1, const pii& p2){
        return p1.first > p2.first;
    }
};
struct Graph{
    int v;
    vector<vector<pii>>adjacency_list;
    vector<bool>path_found;
    vector<int>distances;
    vector<int>police_stations;
    priority_queue<pii, vector<pii>, comparator>heap;
};
void init_graph(Graph& g, int v){
    g.v=v;
    g.adjacency_list.resize(v);
    g.distances.resize(v,INF);
    g.path_found.resize(v,false);
}
void add_edge(Graph& g, int u, int v){
    g.adjacency_list[u].push_back(make_pair(v,1));
    g.adjacency_list[v].push_back(make_pair(u,1));
}
void deconstruct(const pii& P, int& v, int& toV){
    v=P.first;
    toV=P.second;
}
void dijkstra(Graph& g){
    int u,toU;
    while(!g.heap.empty()){
        deconstruct(g.heap.top(), u, toU);
        g.heap.pop();
        if(g.path_found[u]) continue;

        g.path_found[u]=true;
        int v,toV;
        for(pii tmp : g.adjacency_list[u]){
            deconstruct(tmp,v,toV);
            if(toU+toV < g.distances[v]){
                g.distances[v]=toU+toV;
                g.heap.push(make_pair(v,g.distances[v]));
            }
        }
    }
}
void closest_police_stations(Graph& g){
    for(int station : g.police_stations){
        g.heap.push(make_pair(station, 0));
        g.distances[station]=0;
    }
    dijkstra(g);
    for(int i=0; i<g.v; i++){
        cout<<"closest police station from city "<<i<<" is "<<g.distances[i]<<" miles away"<<endl;
    }

}
void add_police_station(Graph& g, int station){
    g.police_stations.push_back(station);
}
int main() {    
    

    return 0;
}
