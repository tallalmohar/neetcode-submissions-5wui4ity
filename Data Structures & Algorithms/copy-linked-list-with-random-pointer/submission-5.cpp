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
        unordered_map<Node*,Node*> s;
        s[NULL] = NULL;
        Node* curr = head;
        while(curr != NULL){
            Node* node = new Node(curr->val);
            s[curr] = node;
            curr = curr->next;
        }

        curr = head;
        while(curr != NULL){
            Node* copy = s[curr];
            copy->next = s[curr->next];
            copy->random = s[curr->random];
            curr = curr->next;
        }
        return s[head];
    }
};
