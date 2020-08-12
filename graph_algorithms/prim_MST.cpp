#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int INF=numeric_limits<int>::max();
struct Graph{
    int v;
    vector<bool>included_in_MST;
    int** matrix;
    vector<int>parents;
    vector<int>edge_cost;
};
void init_graph(Graph& g, int v){
    g.v=v;
    g.included_in_MST.resize(v,false);
    g.matrix=(int**)malloc(v*sizeof(int*));
    for(int i=0; i<v; i++){
        g.matrix[i]=(int*)malloc(v*sizeof(int));
    }
    g.edge_cost.resize(v,INF);
    g.parents.resize(v,-1);
}
void add_edge(Graph& g, int u, int v, int weight){
    g.matrix[u][v]=weight;
    g.matrix[v][u]=weight;
}
int min_edge_not_included(Graph& g){
    int min=INF;
    int min_index=-1;
    for(int i=0; i<g.v; i++){
        if(!g.included_in_MST[i] && g.edge_cost[i] < min) {
            min=g.edge_cost[i];
            min_index=i;
        }
    }
    return min_index;
}
void prim(Graph& g, int start){
    g.edge_cost[start]=0;
    int node;
    for(int i=0; i<g.v-1; i++) {
        node=min_edge_not_included(g);

        g.included_in_MST[node]=true;
        for(int v=0; v<g.v; v++) {
            if(g.matrix[node][v] && g.included_in_MST[v]==false && g.matrix[node][v] < g.edge_cost[v]) {
                g.edge_cost[v]=g.matrix[node][v];
                g.parents[v]=node;
            }
        }
    }
    int cost=0;
    for(int i=0; i<g.v; i++) {
        if(i!=start)
        cost+=g.edge_cost[i];
    }
    cout<<cost<<endl;
}
int main() {
    



    return 0;
}
