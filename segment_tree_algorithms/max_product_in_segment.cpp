#include<bits/stdc++.h>
using namespace std;
struct Node {
    int largest;
    int second_largest;
};
void build_segment_tree(vector<int>& array, vector<Node>& segment_tree, int x, int y, int k) {
    if(x==y) {
        segment_tree[k].largest=array[x];
        segment_tree[k].second_largest=INT_MIN;
        return;
    }
    int middle=(x+y)/2;
    build_segment_tree(array,segment_tree, x, middle, 2*k + 1);
    build_segment_tree(array,segment_tree, middle+1, y, 2*k + 2);

    segment_tree[k].largest=max(segment_tree[2*k + 1].largest, segment_tree[2*k + 2].largest);
    segment_tree[k].second_largest=min(max(segment_tree[2*k+ 1].largest, segment_tree[2*k + 2].second_largest), max(
        segment_tree[2*k + 2].largest, segment_tree[2*k + 1].second_largest
    ));
}
Node find_max_product(vector<Node>& segment_tree, int x, int y, int k, int a, int b) {
    Node result;
    result.second_largest=INT_MIN;
    result.largest=INT_MIN;

    if(x > b || a>y)
        return result;
    if(x>=a && y<=b)
        return segment_tree[k];
    int middle=(x+y)/2;
    Node left=find_max_product(segment_tree, x, middle, 2*k+1, a,b);
    Node right=find_max_product(segment_tree, middle+1, y, 2*k+2, a, b);

    result.largest=max(left.largest, right.largest);
    result.second_largest=min(max(left.largest, right.second_largest), max(right.largest, left.second_largest))

    return result;
}
int main() {

    return 0;
}