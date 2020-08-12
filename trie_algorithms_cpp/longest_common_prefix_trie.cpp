#include<bits/stdc++.h>
using namespace std;
struct Node {
    bool is_leaf;
    unordered_map<char, Node*>nodes;
};
Node* create_node() {
    Node* new_node= new Node();
    new_node->is_leaf=false;
    return new_node;
}
void add_word(Node* root, string& word, int i) {
    if(i==(int)word.size()) {
        root->is_leaf=true;
        return;
    }
    auto it=root->nodes.find(word[i]);
    if(it==root->nodes.end())
        root->nodes[word[i]]=create_node();
    return add_word(root->nodes[word[i]], word, i+1);
}
void LCP(Node* root, string& lcp) {
    while(root && root->nodes.size()==1 && !root->is_leaf) {
        auto element=root->nodes.begin();
        lcp+=element->first;
        root=element->second;
    }
}
int main() {
    

    return 0;
}
