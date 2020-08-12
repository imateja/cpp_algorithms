#include<bits/stdc++.h>
using namespace std;
struct Graph{ 
    int v;
    vector<int>times;
    vector<int>lower_times;
    int time;
    vector<vector<int>>adjacency_list;
    set<int>articulation_points;
    vector<bool>visited;
    vector<int>parents;

};
void init_graph(Graph& g, int v){
    g.v=v;
    g.adjacency_list.resize(v);
    g.lower_times.resize(v,-1);
    g.times.resize(v,-1);
    g.time=0;
    g.parents.resize(v,-1);
    g.visited.resize(v,false);

}
void add_edge(Graph& g, int u, int v) {
    g.adjacency_list[u].push_back(v);
    g.adjacency_list[v].push_back(u);
}
void DFS(Graph& g, int u) {
    g.visited[u]=true;
    g.lower_times[u]=g.times[u]=g.time;
    g.time++;
    int children=0;

    auto begin=g.adjacency_list[u].begin();
    auto end=g.adjacency_list[u].end();

    while(begin!=end) {
        if(!g.visited[*begin]) {
            g.parents[*begin]=u;
            DFS(g,*begin);
            children++;

            g.lower_times[u]=min(g.lower_times[u],g.lower_times[*begin]);
            if(children>1 && g.parents[u]==-1)
                g.articulation_points.insert(u);
            if(g.parents[u]!=-1 && g.times[u]<=g.lower_times[*begin])
                g.articulation_points.insert(u);
        }
        else if(*begin!=g.parents[u]) {
            g.lower_times[u]=min(g.lower_times[u],g.times[*begin]);
        }
        begin++;
    }
}
void find_articulation_points(Graph& g) {
    DFS(g,3);
    for(int x: g.articulation_points) {
        cout<<x<<" ";
    }
    cout<<endl;
}
int main() {
    

    return 0;
}
