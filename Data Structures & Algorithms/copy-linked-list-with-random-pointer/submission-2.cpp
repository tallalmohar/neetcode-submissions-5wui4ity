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
        unordered_map<Node*,Node*> copySet;
        copySet[NULL] = NULL;
        Node* curr = head;
        while(curr != nullptr){
            Node* copy = new Node(curr->val);
            copySet[curr] = copy;
            curr = curr->next;
        }
        curr = head;
        while(curr != nullptr){
            Node* copy = copySet[curr];
            copy->next = copySet[curr->next];
            copy->random = copySet[curr->random];
            curr = curr->next;
        }
        return copySet[head];
    }
};
