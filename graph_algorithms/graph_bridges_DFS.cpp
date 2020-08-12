#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
using namespace std;
struct Graph {
    int v;
    vector<vector<int>>adjacency_list;
    vector<bool> visited;
    vector<int> degrees;
    vector<int> times;
    vector<int> lower_times;
    stack<int> stack;
    int time;
    vector<bool>in_stack;
    vector<int>parents;

};
void initialize_graph(Graph& g, int v) {
    g.v=v;
    g.adjacency_list.resize(v);
    g.visited.resize(v, false);
    g.degrees.resize(v,0);
}
void add_edge(Graph& g, int u, int v) {
    g.adjacency_list[u].push_back(v);
    g.adjacency_list[v].push_back(u);
    g.degrees[u]++;
    g.degrees[v]++;
}

void DFS_bridges(Graph& g, int u) {
    g.visited[u]=true;
    g.times[u]=g.lower_times[u]=g.time;
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

            if(g.times[u] < g.lower_times[*begin])
                cout<< u<< " -> " << *begin<<endl;
             
        }
        else if(*begin!=g.parents[u]) {
            g.lower_times[u]=min(g.lower_times[u], g.times[*begin]);
        }

        begin++;
    }

}
int main() {

    return 0;
}
