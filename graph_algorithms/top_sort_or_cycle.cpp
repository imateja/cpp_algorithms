#include<bits/stdc++.h>
using namespace std;
struct Graph {
    int v;
    vector<int>degrees;
    vector<vector<int>>adjacency_list;
    bool found;
    vector<bool>visited;
};
void init_graph(Graph& g, int v) {
    g.v=v;
    g.degrees.resize(v,0);
    g.adjacency_list.resize(v);
    g.found=false;
    g.visited.resize(v,false);
}
void add_edge(Graph& g, int u, int v) {
    g.adjacency_list[u].push_back(v);
    g.degrees[v]++;
}
void top_sort(Graph& g, vector<int>& result) {
    queue<int>nodes;
    for(int i=0; i<g.v; i++) {
        if(!g.degrees[i])
        nodes.push(i);
    }
    while(!nodes.empty()) {
        int tmp=nodes.front();
        nodes.pop();
        result.push_back(tmp);

        for(int x : g.adjacency_list[tmp]) {
            g.degrees[x]--;
            if(g.degrees[x]==0)
            nodes.push(x);
        }
    }
}
void DFS(Graph& g, int u, vector<int>& result, int start_node) {
    if(g.visited[u] && u==start_node) {
        g.found=true;
        result.push_back(u);
        return;
    }
    g.visited[u]=true;
    auto begin=g.adjacency_list[u].begin();
    auto end=g.adjacency_list[u].end();
    while(begin!=end){
        if(!g.found)
            DFS(g,*begin,result,start_node);
        begin++;
    }
}
void funkcija(Graph& g) {
    bool topological=true;
    vector<int>result;
    top_sort(g,result);
    for(int i=0; i<g.v; i++) {
        if(g.degrees[i])
        topological=false;
    }
    if(topological) {
        for(int i=0; i<result.size(); i++) {
            cout<<result[i]<<" ";
        }
        cout<<endl;
        return;
    }
    else {
        result.clear();
        int start;
        for(int i=0; i<g.v; i++) {
            if(g.degrees[i]) {
                DFS(g,i,result,i);

            int j;
            for(int j=0; j<result.size()-1; j++) {
                cout<<result[j]<<" ";
            }
            cout<<"CYCLE"<<endl;
            return;
            }
            
        }
    
    }
}
int main() {
   

    return 0;
}
