#include<bits/stdc++.h>
using namespace std;
void build_segment_tree(vector<int>& array, vector<int>& segment_tree, int x, int y, int k) {
    if(x==y) {
        segment_tree[k]=array[x];
        return ;
    }
    int middle=(x+y)/2;

    build_segment_tree(array, segment_tree, x, middle, 2*k +1);
    build_segment_tree(array,segment_tree,middle+1, y, 2*k+2);

    segment_tree[k]=max(segment_tree[2*k + 1], segment_tree[2*k +2]);
}
void update_tree(vector<int>&segment_tree, int x, int y, int k, int value, int pos) {
    if(x==y) {
        segment_tree[k]=value;
        return ;
    }
    int middle=(x+y)/2;
    if(pos<= middle)
        update_tree(segment_tree, x, middle, 2*k +1, value, pos);
    else 
        update_tree(segment_tree, middle+1, y, 2*k + 2, value, pos);
    
    segment_tree[k]=segment_tree[2*k + 1] + segment_tree[2*k +2];
}
int max_element_in_segment(vector<int>& segment_tree, int x, int y, int k, int a, int b) {
    if(x > b || y < a)
        return INT_MIN;
    if(x>=a && y<=b)
        return segment_tree[k];
    int middle=(x+y)/2;
    return max(max_element_in_segment(segment_tree, x, middle, 2*k +1, a, b), max_element_in_segment(segment_tree, middle+1, y, 2*k + 2, a, b));
}
int main() {
    std::vector<int> array = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int n=array.size();
    int height=ceil(log2(n));

    int size=2*pow(2,height) -1;
    vector<int>segment_tree(size);
    build_segment_tree(array, segment_tree, 0, n-1, 0);
    for(int x : segment_tree) {
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}