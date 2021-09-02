#include <iostream>
#include <unordered_map>
using namespace std;

struct Trie{
    bool isLeaf{false};
    unordered_map<char, Trie*> children;
};

void insert(Trie*& root, const string& str) {
    if(root==nullptr) root = new Trie();
    Trie* curr = root;
    for(char c : str) {
        if(curr->children.count(c) == 0) curr->children[c] = new Trie();
        curr = curr->children[c];
    }
    curr->isLeaf = true;
}

bool search(Trie* root, const string& str) {
    if(root == nullptr) return false;
    Trie* curr = root;
    for(char c : str) {
        if(curr->children.count(c) == 0) return false;
        curr = curr->children[c];
    }
    return curr->isLeaf;
}