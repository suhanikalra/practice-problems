class Node{
  public:
    int key;
    int value;
    Node* prev;
    Node* next;
};

class LRUCache {
public:
map<int , Node* >cache;
Node* head;
Node* tail;
int capacity;
public: void addNode(Node* node){
    Node* nextNode= head->next;
    head->next= node;
    node->next=nextNode;
    node->prev=head;
    nextNode->prev= node;
}
public: void delNode(Node* node){
    Node* nextNode= node->next;
    node->prev->next=nextNode;
    nextNode->prev= node->prev;
    
}

 
    LRUCache(int capacity) {
        this->capacity= capacity;
        tail= new Node();
        head= new Node();
        head->next= tail;
        head->prev= NULL;
        tail->next= NULL;
        tail->prev= head;
    }
    
    int get(int key) {
        if( cache.find( key)!= cache.end()){
            Node* oldNode= cache[key];
            delNode(oldNode);
            addNode(oldNode);
            return oldNode->value;
        
        } 
        return -1;
    }
    
    void put(int key, int value) {

    if (cache.find(key) != cache.end()) {
        Node* node = cache[key];
        node->value = value;
        delNode(node);
        addNode(node);
        return;
    }

    if (cache.size() == capacity) {
        Node* lru = tail->prev;
        cache.erase(lru->key);
        delNode(lru);
        delete lru;
    }

    Node* newNode = new Node();
    newNode->key = key;
    newNode->value = value;

    cache[key] = newNode;
    addNode(newNode);
}


        
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */