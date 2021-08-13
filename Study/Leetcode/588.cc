class FileSystem {
    map<int,map<string,pair<int,bool>>> fs;
    map<int,string> fileContents;
    int nodeCounter;
public:
    FileSystem(): nodeCounter{0} {
        
    }
    
    string readstring(string& path) {
        int i{0};
        for(; i < path.size(); ++i) if(!(path[i] == '/' || path[i] == ' ')) break;
        string ans = "";
        for(; i < path.size(); ++i) if(!isalpha(path[i])) break; else ans += path[i];
        path = path.substr(i);
        return ans;
    }
    
    vector<string> ls(string path) {
        int node{0};
        string str;
        bool file = false;
        while(!path.empty()) {
            str = readstring(path);
            if(str != "") {
                auto [next_node, isfile] = fs[node][str];
                file = isfile;
                node = next_node;
            }
        }
        vector<string> ans;
        if(file) ans.push_back(str);
        else {
            for(auto [s, _] : fs[node]) {
                ans.push_back(s);
            }
        }    
        return ans;
    }
    
    void mkdir(string path) {
        int node{0}, next_node;
        string str;
        while(!path.empty()) {
            str = readstring(path);
            if(str != "") {
                if(fs.count(node) == 0) {
                    fs[node][str] = {++nodeCounter, false};
                    next_node = nodeCounter;
                }
                else if(fs[node].count(str) == 0) {
                    fs[node][str] = {++nodeCounter, false};
                    next_node = nodeCounter;
                }
                else {
                    next_node = fs[node][str].first;
                }
                node = next_node;
            }
        }
    }
    
    void addContentToFile(string filePath, string content) {
        int node{0}, next_node;
        bool file;
        string str;
        while(!filePath.empty()) {
            str = readstring(filePath);
            if(str != "") {
                if(fs[node].count(str)) {
                    auto [next_node, isfile] = fs[node][str];
                    file = isfile;
                    node = next_node;   
                }
                else {
                    fs[node][str] = {++nodeCounter, true};
                }
            }
        }
        fileContents[nodeCounter] += content;
    }
    
    string readContentFromFile(string filePath) {
        int node{0}, next_node;
        bool file;
        string str;
        while(!filePath.empty()) {
            str = readstring(filePath);
            if(str != "") {
                auto [next_node, isfile] = fs[node][str];
                file = isfile;
                node = next_node;
            }
        }
        return fileContents[node];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */