#include<bits/stdc++.h>
using namespace std;
void build_segment_tree(vector<int>& array, vector<int>&segment_tree, int x, int y, int k) {
    if(x==y) {
        if(array[x] % 2==0)
            segment_tree[k]=1;
        else
            segment_tree[k]=0;
        return;
    }
    int middle=(x+y)/2;

    build_segment_tree(array, segment_tree, x, middle, 2*k + 1);
    build_segment_tree(array,segment_tree, middle+1, y, 2*k+2);

    segment_tree[k]=segment_tree[2*k+1] + segment_tree[2*k + 2];
}
int count_even_elements(vector<int>& segment_tree, int x, int y, int a, int b, int k) {
    if(x> b || y < a)
        return 0;
    if(x>=a && y<=b)
        return segment_tree[k];
    int middle=(x+y)/2;
    return count_even_elements(segment_tree, x, middle, a, b, 2*k+1) + count_even_elements(segment_tree, middle+1, y, a,b,2*k + 2);
}
int main() {

    return 0;
}