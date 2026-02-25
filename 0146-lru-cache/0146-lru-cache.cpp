class Node{
    public:

    Node* next;
    Node* prev;
    int key,val;

    Node(int k,int v){
        this->key=k;
        this->val= v;
        next = NULL;
        prev = NULL;
    }
    
};
class LRUCache {
public:
int cap=0;
unordered_map<int,Node*>cacheMap;
Node* head;Node* tail;

void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNode(Node* node) {
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    LRUCache(int capacity) {
        head= new Node(-1,-1);
        tail= new Node(-1,-1);
        this->cap= capacity;
        head->next= tail;
        tail->prev= head;
    }
    
    int get(int key) {
        if( cacheMap.find(key)==cacheMap.end())return -1;
        auto node= cacheMap[key];
        auto ans= node->val;
        deleteNode(node);
        addNode(node);
        return ans;
    }
    
    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            auto node = cacheMap[key];
            node->val = value;
            deleteNode(node);
            addNode(node);

        } else {
            if (cacheMap.size() == cap) {
                auto lastnode = tail->prev;
                cacheMap.erase(lastnode->key);
                deleteNode(lastnode);
            }

            cacheMap[key] = new Node(key,value);
            addNode(cacheMap[key]);
        
        }    
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */