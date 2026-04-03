class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k,int v) : key(k), val(v), next(nullptr),prev(nullptr) {}

};
class LRUCache {
private:
    int cap;
    unordered_map<int,Node*> cache;
    Node* left;
    Node* right;

    void insert(Node* node){
        Node* prevNode = right->prev;
        node->prev = prevNode;
        prevNode->next = node;
        right->prev = node;
        node->next = right;
    }

    void remove(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        right = new Node(0,0);
        left = new Node(0,0);
        right->prev = left;
        left->next = right;    
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
        }
        Node* newNode = new Node(key,value);
        insert(newNode);
        cache[key] = newNode;
        if(cache.size() > cap){
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete(lru);
        }    
    }
};
