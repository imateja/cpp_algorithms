#include<bits/stdc++.h>
using namespace std;
class Point{
public:
    Point(){

    }
    Point(int _x, int _y){
        x=_x;
        y=_y;
    }
    int getX() const {return x; }
    int getY() const {return y; }

private:
int x;
int y;
};
Point p_0;
void swap(Point& p1, Point& p2){
    Point tmp=p1;
    p1=p2;
    p2=tmp;
}
int orientation(Point p, Point q, Point r ){
    int val=(q.getY() - p.getY())*(r.getX() - q.getX()) - (q.getX() - p.getX())*(r.getY() - q.getY());
    if(val==0) return 0;
    return (val>0) ? 1 : 2;
}
bool compare(Point& p1, Point& p2){
    int orient=orientation(p_0, p1, p2);
    if(!orient){
        cout<<"Yes"<<endl;
        exit(EXIT_SUCCESS);
    }
    return orient==2;
}
void threeColinear(vector<Point>& points){
    int n=points.size();
    for(int i=0; i<n; i++){
        swap(points[0], points[i]); 
        p_0=points[0];
        sort(points.begin()+1, points.end(), compare);
    }
}
int main(){

    return 0;
}