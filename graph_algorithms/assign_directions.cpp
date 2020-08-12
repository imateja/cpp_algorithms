#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
struct Graph {
    int v;
    vector<vector<int>>adjacenct_list;
    vector<pii>added_edges;
    vector<pii>undirected_edges;
    vector<pii>edges;
    vector<int>position_in_top_sort;
    vector<bool>visited;
    vector<int>in_degrees;
};
void init_graph(Graph& g, int v){
    g.v=v;
    g.adjacenct_list.resize(v);
    g.position_in_top_sort.resize(v, -1);
    g.visited.resize(v,false);
    g.in_degrees.resize(v,0);
}
void add_directed_edge(Graph& g, int u, int v) {
    g.adjacenct_list[u].push_back(v);
    g.in_degrees[v]++;

    pii p(u,v);
    g.edges.push_back(p);
}
void add_undirected_edge(Graph& g, int u, int v) {
    pii p(u,v);
    g.undirected_edges.push_back(p);
}
void top_sort(Graph& g) {
    queue<int>nodes;
    for(int i=0; i<g.v;i++) {
        if(g.in_degrees[i])
        nodes.push(i);
    }
    int tmp;
    int position=0;
    while(!nodes.empty()) {
        tmp=nodes.front();
        nodes.pop();
        g.position_in_top_sort[tmp]=position;
        position++;

        for(int node : g.adjacenct_list[tmp]) {
            g.in_degrees[node]--;
            if(g.in_degrees[node]==0)
            nodes.push(node);
        }
    }
}
bool DFS(Graph& g, int u) {
    g.visited[u]=true;
    auto begin=g.adjacenct_list[u].begin();
    auto end=g.adjacenct_list[u].end();

    while(begin!=end){
        if(g.visited[*begin])
            return true;
        else if(DFS(g,*begin))
            return true;
        begin++;
    }
    g.visited[u]=false;
    return false;
}
void assign_directions(Graph& g) {
    top_sort(g);
    for(auto p : g.undirected_edges) {
        if(g.position_in_top_sort[p.first] < g.position_in_top_sort[p.second]) {
            add_directed_edge(g,p.first,p.second);
            g.added_edges.push_back(make_pair(p.first, p.second));
        }
        else {
            add_directed_edge(g,p.second,p.first);
            g.added_edges.push_back(make_pair(p.second, p.first));
        }
    }
    if(DFS(g,0)) {
        cout<<"Has a cycle"<<endl;
    }
    else  {
        cout<<"DOesnt have a cycle"<<endl;
    }
}
void add_edges(Graph& g) {
    top_sort(g);
    for(int i=0; i<g.v; i++) {
        for(int y : g.adjacenct_list[g.top[i]])
            g.visited[y]=true;
            for(int j=i+1; j<g.v; j++) {
                if(!g.visited[g.top[j]]) {
                    add_directed_edge(g,g.top[i], g.top[j]);
                }
                g.visited[g.top[j]]=false;
            }
    }
}
int main() {
     

    return 0;
}
