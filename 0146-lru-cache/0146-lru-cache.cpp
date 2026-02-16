class Node{
    public: 

    int key,val;
    Node* next;
    Node* prev;

    Node(int k,int v){
        key= k;
        val=v;
        next=NULL;
        prev=NULL;
    }
};

class LRUCache {
public:

unordered_map<int, Node*>cacheMap;
int cap;
Node* head; Node* tail;

void insertAtHead(Node* node ){
    Node* temp= head->next;
    node->next = temp; 
    head->next= node;
    temp->prev=node;
    node->prev= head;

}

void deleteNode(Node* node){
    node->prev->next=node->next;
    node->next->prev= node->prev;
}

    LRUCache(int capacity) {
        cap= capacity;
        head= new Node(-1,-1);
        tail= new Node(-1,-1);
        head->next= tail;
        head->prev=NULL;
        tail->next=NULL;
        tail->prev=head;

    }
    
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end())
            return -1;

        Node* node = cacheMap[key];
        int ans = node->val;

        deleteNode(node);
        insertAtHead(node);

        return ans;
        
    }
    
    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            Node* node = cacheMap[key];
            node->val = value;

            deleteNode(node);
            insertAtHead(node);
        }
        else {
            if (cacheMap.size() == cap) {
                Node* lru = tail->prev;
                cacheMap.erase(lru->key);
                deleteNode(lru);
                delete lru;
            }

            Node* newNode = new Node(key, value);
            cacheMap[key] = newNode;
            insertAtHead(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */