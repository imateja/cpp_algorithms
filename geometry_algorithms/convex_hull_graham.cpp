#include<bits/stdc++.h>

Point p0;
int swap(Point& p1, Point& p2) {
    Point tmp;
    tmp=p1;
    p1=p2;
    p2=tmp;
}
int dist(Point p1, Point p2) {
    return (p1.x - p2.x )*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y -p2.y);
}
int orientation(Point p, Point q, Point r) {
    int val= (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);
    if(val==0) return 0; 
    return val>0 ? 1 : 2; 
}
int compare(const void* vp1, const void* vp2) {
    Point* p1=(Point*)vp1;
    Point* p2=(Point*)vp2;

    int o=orientation(p0, *p1, *p2);
    if(o==0) {
        return (dist(p0, *p2) >= dist(p0, *p1)) ? -1 : 1;
    }
    return (o==2) ? -1 : 1;
}

class Point {
    public:
        Point() {}
        Point(int _x, int _y) {
            x=_x;
            y=_y;
        }
        int get_x() const {return x;}
        int get_y() const {return y;}

        int x;
        int y;
};
Point p_0;

void graham(vector<Point>& points) {
    int extreme_index=find_extreme_point(points);
    swap(points[0], points[extreme_index]);

    p_0=points[0];

    sort(points.begin() +1, points.end(), compare);

    vector<Point> result;
    result.push_back(points[0]);
    result.push_back(points[1]);

    int n=points.size();
    int m=1;

    for(int k=2; k<n; k++) {
        while(result.size()>=2 && orientation(points[m-1], points[m], points[k])!=2) {
            result.pop_back();
            m--;
        }
        m++;
        result.push_back(points[k]);
    }
    for(Point& p:result) {
        cout<< p.get_x() << " "<<p.get_y()<< endl; 
    }
}
int main() {

    return 0;
}
