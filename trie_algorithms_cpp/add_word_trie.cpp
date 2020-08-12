#include <bits/stdc++.h>
using namespace std;

struct Node {
    string word;
    unordered_map<char, Node*> nodes;
    int count;
};
Node* create_node() {
    Node* new_node= new Node();
    new_node->word="";
    new_node->count=0;
    return new_node;
}
void add_word(Node* root, string &word, int i) {
    if(i==(int)word.size()) {
        root->word=word;
        root->count++;
        return;
    }
    auto it=root->nodes.find(word[i]);
    if(it==root->nodes.end())
        root->nodes[word[i]]= create_node();

    add_word(root->nodes[word[i]], word, i+1);
}
struct comparator {
    bool operator()(Node* n1, Node* n2) {
        return n1->count < n2->count;
    }
}
void free_tree(Node* root) {
    if(root==nullptr)
        return;
    for(auto &p : root->nodes)
        free_tree(p.second);
    delete root;
}

int main() {
    vector<string> words = {"code", "coder", "coding", "codable", "codec", "codecs", "coded",
		"codeless", "codec", "codecs", "codependence", "codex", "codify",
		"codependents", "codes", "code", "coder", "codesign", "codec",
		"codeveloper", "codrive", "codec", "codecs", "codiscovered"};
    Node* root=create_node();

    for(string s: words)
        add_word(root, s,0);
    int max=0;
    priority_queue<Node*, vector<Node*> >,comparator> heap;

    free_tree(root);
    return 0;
}
