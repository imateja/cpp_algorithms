#include<bits/stdc++.h>
using namespace std;

struct Graph {
    int v;
    int** matrix;
};
void init_graph(Graph& g, int v) {
    g.v=v;
    g.matrix=(int**)malloc(v*sizeof(int*));
    for(int i=0; i<v; i++) {
        g.matrix[i]=(int*)malloc(v*sizeof(int));
    }
    for(int i=0; i<v; i++) {
        for(int j=0; j<v; j++) {
            if(i==j) {
                g.matrix[i][j]=0;
            }
            else {
                g.matrix[i][j]=INFINITY;
            }
        }
    }
}
void add_edge(Graph&g, int u, int v, int weight) {
    g.matrix[u][v]=weight;
}
void floyd_warshal(Graph& g){
    for(int k=0; k<g.v; k++) {
        for(int i=0; i<g.v; i++) {
            for(int j=0; j<g.v; j++) {
                if(g.matrix[i][j] > g.matrix[i][k] + g.matrix[k][j]) {
                    g.matrix[i][j]=g.matrix[i][k] + g.matrix[k][j];
                }
            }
        }
    }
    for(int i=0; i<g.v; i++) {
        if(g.matrix[i][i] < 0){
             cout<<"YES"<<endl;
             return;
        }
    }
    cout<<"NO"<<endl;
}
int main() {
  

    return 0;
}