#include<bits/stdc++.h>
using namespace std;
struct Node {
    bool is_leaf;
    string word; 
    unordered_map<char, Node*>nodes;
};
Node* create_node() {
    Node* new_node= new Node();
    new_node->word="";
    new_node->is_leaf=false;
    return new_node;
}
void add_word(Node* root, string& word, int i) {
    if(i==(int)word.size()) {
        root->word=word;
        root->is_leaf=true;
        return ;
    }
    auto it=root->nodes.find(word[i]);
    if(it==root->nodes.end())
        root->nodes[word[i]]=create_node();
    add_word(root->nodes[word[i]],word, i+1);
}
Node* autocomplete(Node* root, string& prefix, int i) {
    if(i==(int)prefix.size()) {
        return root;
    }
    auto it=root->nodes.find(prefix[i]);
    if(it==root->nodes.end())
        return nullptr;
    return autocomplete(root->nodes[prefix[i]], prefix, i+1);
}
void print(Node* root) {
    if(root->is_leaf) {
        cout<<root->word<<endl;
    }
    auto begin=root->nodes.begin();
    auto end=root->nodes.end();

    while(begin!=end) {
        print(begin->second);
        begin++;
    }
}
int main () {
    
    return 0;
}
