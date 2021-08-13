class Solution {
    int V;
    vector<vector<int>> AdjList;
    vector<int> dist, visited;
    const int INF = 2e9;
public:
    bool cmp(const string& word, const string& other) {
        int different{0};
        for(int i = 0; i < word.size(); ++i) {
            if(word[i] != other[i]) different++;
            if(different > 1) return false;
        }
        return different == 1;
    }
    
    void addNeighbors(const string& beginWord, int nodeId, vector<string>& wordList) {
        int i{1};
        for(const string& word : wordList) {
            i++;
            bool neighbors = cmp(beginWord, word);
            if(neighbors) AdjList[nodeId].push_back(i);
        }
    }
    
    void bfs(int start) {
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        visited[start] = true;
        while(!q.empty()) {
            auto u = q.front(); q.pop();
            for(auto v : AdjList[u])
                if(!visited[v])
                    dist[v] = dist[u] + 1, q.push(v), visited[v] = true;
        }
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        V = wordList.size()+1;
        AdjList.resize(V+1);
        dist.assign(V+1,INF);
        visited.assign(V+1, false);
        addNeighbors(beginWord, 1, wordList);
        int endNodeId{0};
        for(int i = 0; i < wordList.size(); ++i) {
            addNeighbors(wordList[i], i+2, wordList);
            if(endWord == wordList[i]) endNodeId = i+2;
        }
        bfs(1);
        return dist[endNodeId] == INF ? 0 : dist[endNodeId]+1;
    }
};