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
    void setX(int x) {this->x=x;}
    void setY(int y) {this->y=y;}

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
int orientation(Point& p, Point& q, Point& r){
    int val=(q.getY() - p.getY())*(r.getX() - q.getX()) - (q.getX() - p.getX())*(r.getY()-q.getY());
    if(val==0) return 0;
    return (val>0) ? 1 : 2;
}
int distance(Point p1, Point p2){
    return (p1.getX() - p2.getX())*(p1.getX() - p2.getX()) + (p1.getY() - p2.getY())*(p1.getY() - p2.getY());
}
bool compare(Point& p1, Point& p2){
    int orient=orientation(p_0, p1, p2);
    if(orient==2) return true;
    else if(orient==1) return false;
    return distance(p_0, p1) < distance(p_0, p2);
}
int find_extreme_point(vector<Point>& points){
    int min_index=0, max_x=points[0].getX(), min_y=points[0].getY();
    for(int i=1; i<points.size(); i++){
        if(points[i].getX() > max_x) {
            max_x=points[i].getX();
            min_y=points[i].getY();
            min_index=i;
        }
        else if(points[i].getX()==max_x){
            if(points[i].getY() < min_y) {
                min_y=points[i].getY();
                min_index=i;
            }
        }
    }
    return min_index;
}
void convex_hull_graham(vector<Point>& points){
    int extreme_index=find_extreme_point(points);
    swap(points[0], points[extreme_index]);
    p_0=points[0];
    sort(points.begin() + 1, points.end(), compare);
    vector<Point>result;
    result.push_back(points[0]);
    result.push_back(points[1]);
    int n=points.size();
    int m=1;

    for(int k=2; k<n; k++){
        while(result.size()>=2 && orientation(result[m-1], result[m], points[k])==1){
            result.pop_back();
            m--;
        }
        m++;
        result.push_back(points[k]);
    }
    for(int i=0; i<result.size(); i++){
        cout<<result[i].getX()<<" "<<result[i].getY()<<endl;
    }
}
float area(Point& a, Point& b, Point& c){
    return fabs((a.getX()*(b.getY() - c.getY()) + b.getX()*(c.getY() - a.getY()) + c.getX()*(a.getY() - c.getY()))/2.0);
}
bool is_inside(Point& a, Point& b, Point& c, Point& p){
    float A=area(a,b,c);
    float A1=area(p,b,c);
    float A2=area(a,p,c);
    float A3=area(a,b,p);
    return (A==A1+A2+A3);
}
bool binary_search_point(vector<Point>& points, Point& p){
    int l=points.size() -1, r=1, s;
    Point lp=points[l], rp=points[r];
    Point start=points[0];

    while(abs(l-r) > 1){
        s=(l+r)/2;
        if(orientation(start, points[s], p)==1) {
            lp=points[s];
            l=s;
        }
        else {
            r=s;
            rp=points[s];
        }
    }
    return is_inside(start, lp, rp, p);
}
void find_coordinates(const Point& a, const Point& b, Point& c, Point& c_1, Point& d, Point&d_1){
    int deltaX=b.getX() - a.getX();
    int deltaY= b.getY() - a.getY();
    c.setX(b.getX() + deltaY);
    c_1.setX(b.getX() - deltaY);

    c.setY(b.getY() - deltaX);
    c_1.setY(b.getY() +deltaX);

    d.setX(a.getX() + deltaY);
    d_1.setX(a.getX() -deltaY);

    d.setY(a.getY() - deltaX);
    d_1.setY(a.getY() + deltaX);

}
int main(){
     

    return 0;
}
