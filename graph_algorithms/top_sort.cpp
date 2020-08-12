#include<bits/stdc++.h>
using namespace std;
struct Graph{
    int v;
    vector<vector<int>>adjacency_list;
    vector<bool>visited;
    vector<int>in_degrees;
};
void initialize_graph(Graph& g, int v) {
    g.v=v;
    g.adjacency_list.resize(v);
    g.visited.resize(v,false);
    g.in_degrees.resize(v,0);
}
void add_edge(Graph& g, int u, int v) {
    g.adjacency_list[u].push_back(v);
    g.in_degrees[v]++;
}
void topological_sorting(Graph& g) {
    queue<int>nodes;
    for(int i=0; i<g.v; i++) {
        if(!g.in_degrees[i])
        nodes.push(i);
    }
    int tmp;
    while(!nodes.empty()) {
        tmp=nodes.front();
        nodes.pop();

        cout<<tmp<< " ";

        auto begin=g.adjacency_list[tmp].begin();
        auto end=g.adjacency_list[tmp].end();
        while(begin!=end) {
            g.in_degrees[*begin]--;
            if(!g.in_degrees[*begin])
            nodes.push(*begin);

            begin++;
        }

    }
    cout<<endl;
}
int main() {


    return 0;
}
