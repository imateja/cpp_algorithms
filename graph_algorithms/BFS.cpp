#include<bits/stdc++.h>
using namespace std;
struct Graph {
    int v;
    vector<vector<int>>adjacency_list;
    vector<bool>visited;
};
void add_edge(Graph& g, int u, int v) {
    g.adjacency_list[u].push_back(v);
    g.adjacency_list[v].push_back(u);
}
void init_graph(Graph& g, int v) {
    g.v=v;
    g.adjacency_list.resize(v);
    g.visited.resize(v,false);
}
void BFS(Graph& g, int u) {
    queue<int>nodes;
    nodes.push(u);
    int tmp;
    g.visited[u]=true;
    while(!nodes.empty()) {
        tmp=nodes.front();
        nodes.pop();

        cout<<tmp<<" ";
        auto begin=g.adjacency_list[tmp].begin();
        auto end=g.adjacency_list[tmp].end();

        while(begin!=end) {
            if(!g.visited[*begin]) {
                g.visited[*begin]=true;
                nodes.push(*begin);
            }
            begin++;
        }
    }
    cout<<endl;
}
int main() {
    

    return 0;
}
