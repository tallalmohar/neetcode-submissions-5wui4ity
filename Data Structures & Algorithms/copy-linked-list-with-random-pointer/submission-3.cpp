/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>set;
        set[NULL] = NULL;
        Node* curr = head;
        while(curr){
            Node* copy = new Node(curr->val);
            set[curr] = copy;
            curr = curr->next;
        }
        curr = head;
        while(curr){
            Node* node = set[curr];
            node->next = set[curr->next];
            node->random = set[curr->random];
            curr = curr->next;
        }
        return set[head];
    }
};
