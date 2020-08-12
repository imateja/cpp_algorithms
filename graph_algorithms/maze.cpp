#include<bits/stdc++.h>
using namespace std;
const int INF=numeric_limits<int>::max();
class cell {
    public:
    cell() {

    }
    cell(int x, int y, int val) {
        this->i=x;
        this->j=y;
        this->dist=val;
    }
    int i;
    int j;
    int dist;

};
struct Graph {
    int v;
    int** distances;
};
void init_graph(Graph& g, int v) {
    g.v=v;
    g.distances=(int**)malloc(v*sizeof(int*));
    for(int i=0; i<v;i++) {
        g.distances[i]=(int*)malloc(v*sizeof(int));
    }
    for(int i=0; i<v; i++) {
        for(int j=0; j<v; j++) { 
            g.distances[i][j]=INF;
        }
    }
}
struct compare {
    bool operator()(const cell& c1, const cell& c2) {
        return c1.dist < c2.dist;
    }
};
void dijkstra(Graph& g, int maze[5][5], int n) {
    set<cell,compare>skup;
    cell tmp;
    tmp.i=0;
    tmp.j=0;
    tmp.dist=maze[0][0];
    g.distances[0][0]=tmp.dist;
    skup.insert(tmp);

    while(!skup.empty()) {
        tmp=*skup.begin();
        skup.erase(skup.begin());

        if(tmp.i-1>=0 && g.distances[tmp.i-1][tmp.j] > g.distances[tmp.i][tmp.j] + maze[tmp.i-1][tmp.j]) {
            if(g.distances[tmp.i-1][tmp.j]!=INF)
                skup.erase(skup.find(cell(tmp.i-1, tmp.j, g.distances[tmp.i-1][tmp.j])));

            g.distances[tmp.i-1][tmp.j] =g.distances[tmp.i][tmp.j] + maze[tmp.i-1][tmp.j];
            skup.insert(cell(tmp.i-1, tmp.j, g.distances[tmp.i-1][tmp.j]));
        }
        if(tmp.i+1 < n && g.distances[tmp.i+1][tmp.j] > g.distances[tmp.i][tmp.j] + maze[tmp.i+1][tmp.j]) {
            if(g.distances[tmp.i+1][tmp.j]!=INF)
                skup.erase(skup.find(cell(tmp.i+1, tmp.j, g.distances[tmp.i+1][tmp.j])));

            g.distances[tmp.i+1][tmp.j]=g.distances[tmp.i][tmp.j] + maze[tmp.i+1][tmp.j];
            skup.insert(cell(tmp.i+1, tmp.j, g.distances[tmp.i+1][tmp.j]));
        }
        if(tmp.j-1>=0 && g.distances[tmp.i][tmp.j-1] > g.distances[tmp.i][tmp.j] + maze[tmp.i][tmp.j-1]) {
            if(g.distances[tmp.i][tmp.j-1]!=INF)
                skup.erase(skup.find(cell(tmp.i, tmp.j-1, g.distances[tmp.i][tmp.j-1])));

            g.distances[tmp.i][tmp.j-1]= g.distances[tmp.i][tmp.j] + maze[tmp.i][tmp.j-1];
            skup.insert(cell(tmp.i, tmp.j-1, g.distances[tmp.i][tmp.j-1]));
        }
        if(tmp.j+1 < n && g.distances[tmp.i][tmp.j+1] > g.distances[tmp.i][tmp.j] + maze[tmp.i][tmp.j+1]) {
            if(g.distances[tmp.i][tmp.j+1]!=INF)
                skup.erase(skup.find(cell(tmp.i, tmp.j+1, g.distances[tmp.i][tmp.j+1])));

            g.distances[tmp.i][tmp.j+1]= g.distances[tmp.i][tmp.j] + maze[tmp.i][tmp.j+1];
            skup.insert(cell(tmp.i, tmp.j+1, g.distances[tmp.i][tmp.j+1]));
        }
       
    }
    cout<<g.distances[n-1][n-1]<<endl;

}
int main(){
   

  int maze[5][5] = {
        { 31, 100, 65, 12, 18 },
        { 10, 13, 47, 157, 6 },
        { 100, 113, 174, 11, 33 },
        { 88, 124, 41, 20, 140 },
        { 99, 32, 111, 41, 20 }
  };

 

    return 0;
}
