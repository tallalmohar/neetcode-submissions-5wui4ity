class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k,int v) : key(k),val(v),next(nullptr),prev(nullptr) {}
};
class LRUCache {
private:
    int cap;
    unordered_map<int,Node*> cache;
    Node* left;
    Node* right;


    void remove(Node* node){
        Node* nextNode = node->next;
        Node* prevNode = node->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
    }
    
    void insert(Node* node){
        Node* prevNode = right->prev;
        prevNode->next = node;
        node->prev = prevNode;
        right->prev = node;
        node->next = right;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();       
        right = new Node(0,0);
        left = new Node(0,0);
        left->next = right;
        right->prev = left;
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
        cache[key] = newNode;
        insert(newNode);
        if(cache.size() > cap){
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete(lru);
        }
    }
};
