enum ObjType {File, Directory};

struct FileSystemObj{
    ObjType type;
    string content;
    FileSystemObj* parent;
    map<string, FileSystemObj*> children;
    FileSystemObj(ObjType type): type{type} {}
    FileSystemObj(ObjType type, FileSystemObj* parent): type{type}, parent{parent} {}
};

class FileSystem {
    FileSystemObj* root;
    
    vector<string> parse(const string& path) {
        vector<string> ans;
        string current;
        int i{0}, n = path.length();
        for(auto c : path) {
            if(c != '/') current += c;
            if(c == '/' || i == n-1) {
                if(current != "") ans.emplace_back(move(current));
            }
            ++i;
        }
        return ans;
    }
    
public:
    FileSystem() {
        root = new FileSystemObj(Directory);
    }
    
    vector<string> ls(string path) {
        vector<string> path_list = move(parse(path));
        FileSystemObj* current = root;
        for(const auto& token : path_list) {
            current = current->children[token];
        }
        if(current->type == File) return {path_list[path_list.size()-1]};
        vector<string> ans;
        for(const auto& [name, _]: current->children) ans.emplace_back(name);
        return ans;
    }
    
    void mkdir(string path) {
        FileSystemObj* current = root;
        vector<string> path_list = parse(path);
        for(const auto& token : path_list) {
            if(auto it = current->children.find(token); it != current->children.end()) {
                current = it->second;
            }
            else {
                current->children[token] = new FileSystemObj(Directory, current);
                current = current->children[token];
            }
        }
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> path_list = parse(filePath);
        FileSystemObj* current = root;
        int i{0}, n = path_list.size();
        for(const auto& token : path_list) {
            if(auto it = current->children.find(token); it != current->children.end()) {
                current = it->second;
            }
            else {
                if(i == n-1) current->children[token] = new FileSystemObj(File);
                else current->children[token] = new FileSystemObj(Directory, current);
                current = current->children[token];
            }
            ++i;
        }
        current->content += move(content);
    }
    
    string readContentFromFile(string filePath) {
        vector<string> path_list = parse(filePath);
        FileSystemObj* current = root;
        for(const auto& token : path_list) {
            if(auto it = current->children.find(token); it != current->children.end()) {
                current = it->second;
            }
        }
        return current->content;
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