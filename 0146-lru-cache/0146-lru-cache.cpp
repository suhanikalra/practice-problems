class Node{
    public: 
    int val;
    int key;
    Node* next;
    Node* prev;
   
};
class LRUCache {
public:

unordered_map<int,Node*>cache;//key, address;
int capacity;
Node* head;
Node* tail;

 public: void addNode(Node* node){
Node* nextNode= head->next;
head->next= node;
node->prev= head;
node->next= nextNode;
nextNode->prev=node;
 }
  public: void delNode( Node* node){
    node->prev->next= node->next;
    node->next->prev= node->prev;
  }


    LRUCache(int capacity) {
        this->capacity = capacity;
         head=new Node();
         tail= new Node();
        head->next= tail;
        tail->next=NULL;
        head->prev= NULL;
        tail->prev= head;
    }
    
    int get(int key) {
        if(cache.find(key)!= cache.end()){
       
        delNode(cache[key]);
         addNode(cache[key]);
        return cache[key]->val;}
        return -1;
        
    }
    
    void put(int key, int value) {
   
    if (cache.find(key) != cache.end()) {
        Node* node = cache[key];
        node->val = value;
        delNode(node);
        addNode(node);
        return;
    }

 
    if (cache.size() == capacity) {
        Node* lru = tail->prev;       
        delNode(lru);
        cache.erase(lru->key);
        delete lru;
    }

  
    Node* newNode = new Node();
    newNode->key = key;
    newNode->val = value;

    addNode(newNode);
    cache[key] = newNode;
}

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */