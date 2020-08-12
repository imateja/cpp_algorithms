#include<bits/stdc++.h>
using namespace std;
struct Node {
    bool is_leaf;
    unordered_map<char, Node*>nodes;
};
Node* create_node(){
    Node* new_node= new Node();
    new_node->is_leaf=false;
    return new_node;
}
void add_word(Node* root, string& word,  int i) {
    if(i==(int)word.size()) {
        root->is_leaf=true;
        return;
    }
    auto iterator=root->nodes.find(word[i]);
    if(iterator==root->nodes.end())
        root->nodes[word[i]]=create_node();
    add_word(root->nodes[word[i]], word, i+1);
}
bool find_word(Node* root, string& word, int i) {
    if(i==(int)word.size()) {
        return root->is_leaf;    
    }
    auto iterator=root->nodes.find(word[i]);
    if(iterator==root->nodes.end())
        return false;
    return find_word(root->nodes[word[i]], word, i+1);
}
int main() {
    vector<std::string> words = {"cod", "coder", "coding", "codecs"};

  Node *root = create_node();

  for (std::string &s : words)
    add_word(root, s, 0);

  std::string s = "cod";

  // boolalpha nam omogucava da pisemo true i false a ne 0 ili 1
  std::cout << std::boolalpha << find_word(root, s, 0) << std::endl;

    return 0;
}