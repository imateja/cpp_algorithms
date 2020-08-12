#include<bits/stdc++.h>
using namespace std;
struct Node {
    unordered_map<char, Node*>nodes;
    string word;
    int count;

};
Node* create_node() {
    Node* new_node= new Node();
    new_node->count=0;
    new_node->word="";

    return new_node;
}
void add_word(Node* root, string& word, int i) {
    if(i==(int)word.size()) {
        root->word=word;
        root->count++;
        return ;
    }
    auto it=root->nodes.find(word[i]);
    if(it==root->nodes.end())
        root->nodes[word[i]]=create_node();
    add_word(root->nodes[word[i]], word, i+1);
}
void find_max_word(Node* root, string& max_word, int& max) {
    if(root->word!="") {
        int trenutno=root->count;
        if(trenutno > max) {
            max_word=root->word;
            max=trenutno;
        }
        return;
    }
    auto begin=root->nodes.begin();
    auto end=root->nodes.end();

    while(begin!=end) {
        find_max_word(begin->second, max_word, max);
        begin++;
    }
}
int main() {
    

    return 0;
}
