class Node{
public:
    Node* next;
    Node* prev;
    int key,val;

    Node(int k,int v){
        this->key= k;
        val= v;
        next=nullptr;
        prev=nullptr;
    }
};
class LRUCache {
public:
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int,Node*>cache;
    LRUCache(int capacity) {
        cap= capacity;
        head=  new Node(-1,-1);
        tail= new Node(-1,-1);
        head->next= tail;
        tail->prev=head;
    }
    void deleteNode(Node* node){
        node->next->prev= node->prev;
        node->prev->next= node->next;
    }

    void insertAtHead(Node* node){
        node->next= head->next;
        node->next->prev= node;
        node->prev=head;
        head->next= node;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()){return -1;}
        else{
            auto node= cache[key];
            auto ans= node->val;
            deleteNode(node);
            insertAtHead(node);
            return ans;
        }
    }
    
    void put(int key, int value) {
       if(cache.find(key)!=cache.end()){
            auto node= cache[key];
            node->val=value;
            deleteNode(node);
            insertAtHead(node);
            return;
       } 
       else{
        if(cap==cache.size()){
            auto node= tail->prev;
            cache.erase(node->key);
            deleteNode(node);
            

        }
        auto newNode= new Node(key,value);
        insertAtHead(newNode);
        cache[key]=newNode;
        

       }
       return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */