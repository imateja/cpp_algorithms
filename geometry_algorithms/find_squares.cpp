#include<bits/stdc++.h>
using namespace std;
struct Point {
    int x;
    int y;
};
bool compare(const Point& p1,const Point& p2) {
    if(p1.x==p2.x)
        return p1.y < p2.y;
    return p1.x < p2.x;
}
void nadji_tacke(Point& a, Point& b, Point& c, Point& c_1, Point& d, Point& d_1) {
    int deltax=b.x - a.x;
    int deltay=b.y - a.y;

    c.x=b.x + deltay;
    c_1.x=b.x - deltay;

    c.y=b.y - deltax;
    c_1.y=b.y + deltax;

    d.x=a.x + deltay;
    d_1.x=a.x - deltay;

    d.y=a.y - deltax;
    d_1.y=a.y + deltax;
}
bool kvadrat(vector<Point>& points) {
    int n=points.size();
    sort(points.begin(), points.end(), compare);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==j) continue;
            Point c,c_1, d,d_1;
            Point a=points[i], b=points[j];
            nadji_tacke(a,b,c,c_1,d,d_1);
            auto begin=points.begin(), end=points.end();
            if((find(begin, end, c)!=points.end() && find(begin,end, d)!=points.end()) || (find(begin, end, c_1)!=points.end() && find(begin, end, d_1)!=points.end()))
                return true;

        }
    }
    return false;
}
int main() {
    return 0;
}