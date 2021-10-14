#include <iostream>
#include <utility>
#include <cstring>
using namespace std;
const int N{100}, A{26};
int trie[N][A];
bool ends_here[N];
int string_counter[N];
int nodeCounter;

void add_string(string s) {
    int n = s.length(), node{0};
    for(int i = 0; i < n; ++i) {
        string_counter[node]++;
        int ord = s[i] - 'a';
        int& next_node = trie[node][ord];
        if(next_node == 0) next_node = ++nodeCounter;
        if(i == n-1) ends_here[node] = true;
        node = next_node;
    }
    string_counter[node]++;
}

int count_prefix(string s) {
    int n = s.length(), node{0};
    for(int i = 0; i < n; ++i) {
        int ord = s[i] - 'a';
        int next_node = trie[node][ord];
        if(next_node == 0) return 0;
        node = next_node;
    }
    return string_counter[node];
}

int main() {
    add_string("aba");
    add_string("aa");
    add_string("bb");
    cout << count_prefix("a") << endl;
}