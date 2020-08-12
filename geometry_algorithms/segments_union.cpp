#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Segment {
public:
Segment() {}
Segment(int b, int e) {
    begin=b;
    end=e;
}
int getBegin() const {return begin;}
int getEnd() const {return end;}

private:
int begin;
int end;

};
bool compare(Segment& s1, Segment& s2) {
    if(s1.getBegin()==s2.getBegin()) {
        return s1.getEnd() > s2.getEnd();
    }
    return s1.getBegin() < s2.getBegin();
}
void sort_segments(vector<Segment>& segments) {
    sort(segments.begin(), segments.end(), compare);
}
void find_all_segments(vector<Segment>& segments) {
    int max=segments[0].getEnd();
    int n=segments.size();

    for(int i=1; i<n; i++) {
        if(segments[i].getEnd() <= max)
            cout<< "["<< segments[i].getBegin<<", "<<segments[i].getEnd()<<"] ";
        else
        {
                max=segments[i].getEnd();
        }
        
    }
}
// nadji uniju svih segmenata, moram da ignorisem preseke, tipa ako se segment nalazi unutar drugog segmenta
// ignorise se jer on ne doprinosi uniji
int interval_union(vector<Segment>& segments) {
    int right=segments[0].getEnd();
    int sum=segments[0].getEnd() - segments[0].getBegin();
    int n=segments.size();
    for(int i=1; i<n; i++) {
        if(segments[i].getEnd > right) {
            if(segments[i].getBegin() > right) {
                sum+=segments[i].getEnd - segments[i].getBegin() ;
                right=segments[i].getEnd();
            }
            else {
                sum+=segments[i].getEnd() -right;
                right=segments[i].getEnd();
            }
        }
    }
}

int main() {

    return 0;
}
