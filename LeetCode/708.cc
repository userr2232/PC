class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        auto originalNode{head}, current{head};
        Node* new_node = new Node(insertVal);
        if(!current) {
            // list has zero nodes
            new_node->next = new_node;
            return new_node;
        }
        else if(current->next == current) {
            // list has one node
            current->next = new_node;
            new_node->next = current;
        }
        else {
            // list has two nodes or more
            // first: search the "head" node
            bool all_nodes_have_the_same_value = false;
            while(1) {
                if(current->val != current->next->val) break;
                else {
                    if(current->next == originalNode) {
                        all_nodes_have_the_same_value = true;
                        break;
                    }
                    else {
                        current = current->next;
                    }
                }
            }
            // all nodes have the same value
            if(all_nodes_have_the_same_value) {
                new_node->next = current->next;
                current->next = new_node;
            }
            // there are at least two values
            else {
                // search for the "head" node
                while(1) {
                    if(current->next->val < current->val) {
                        current = current->next;
                        break;
                    }
                    else {
                        current = current->next;
                    }
                }
                cout << current->val << endl;
                while(1) {
                    if(current->val <= insertVal && insertVal <= current->next->val || current->next->val < current->val) {
                        new_node->next = current->next;
                        current->next = new_node;
                        break;
                    }
                    else {
                        current = current->next;
                    }
                }
            }
        }
        return originalNode;
    }
};