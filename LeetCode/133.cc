class Solution {
    unordered_map<Node*,Node*> old_to_new;
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        auto it = old_to_new.find(node);
        if(it == old_to_new.end()) old_to_new[node] = new Node(node->val);
        else return it->second;
        for(auto&& neighbor : node->neighbors) {
            old_to_new[node]->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return old_to_new[node];
    }
};