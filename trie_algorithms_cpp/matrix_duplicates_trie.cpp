#include<bits/stdc++.h>
using namespace std;
#define MAX (100)
struct Node {
    int count;
    Node* nodes[2];
};
Node* create_node(){
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->count=0;
    new_node->nodes[0]=new_node->nodes[1]=nullptr;

    return new_node;
}
void add_row(Node* root, int row[MAX], int n, int i, int number) {
    if(i==n) {
        root->count++;
        if(root->count > 1) {
            std::cout << "Duplicate row: #" << number << std::endl;
        }
        return;
    }
    if(root->nodes[row[i]]==nullptr)
        root->nodes[row[i]]=create_node();
    add_row(root->nodes[row[i]], row, n, i+1, number);
}

int main() {

    return 0;
}