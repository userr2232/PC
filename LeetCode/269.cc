class Solution {
public:
    map<char, set<char>> adjList;
    bool cycle = false;
    set<char> in_stack;
    string topo_sort = "";
    set<char> visited;
    
    void add_edge(string a, string b) {
        int l = min(a.size(), b.size());
        bool ok = false;
        for(int i = 0; i < l; ++i) {
            if(a[i] != b[i]) {
                ok = true;
                adjList[a[i]].insert(b[i]);
                break;
            }
        }
        if(a.size() > b.size() && !ok) cycle = true;
        for(auto c : a) {
            adjList[c];
        }
        for(auto c : b) {
            adjList[c];
        }
    }
    
    void DFS(char current) {
        in_stack.insert(current);
        visited.insert(current);
        for(auto v : adjList[current]) {
            if(!visited.count(v))
                DFS(v);
            else if(in_stack.count(v) && current != v) {
                cycle = true;
                return;
            }
        }
        in_stack.erase(current);
        topo_sort += current;
    }
    
    string alienOrder(vector<string>& words) {
        if(words.size() == 1) return words[0];
        // preprocess input and build graph
        for(int i = 1; i < words.size(); ++i) {
            // compare and add edge
            for(int j = i - 1; j >= 0; --j) {
                add_edge(words[j], words[i]);
            }
        }
        // DFS
        for(auto [u, vs] : adjList) {
            if(!visited.count(u))
                DFS(u);
            if(cycle) return "";
        }
        // print
        reverse(topo_sort.begin(), topo_sort.end());
        return topo_sort;
    }
};