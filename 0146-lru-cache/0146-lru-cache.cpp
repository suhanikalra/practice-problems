class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
Node* head;
Node* tail;
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

    int cap;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) { 
        cap = capacity; 
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next= tail;
        tail->prev= head;}

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            auto node = mp[key];
            deleteNode(node);
            addNode(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            auto node = mp[key];
            node->value = value;
            deleteNode(node);
            addNode(node);

        } else {
            if (mp.size() == cap) {
                auto lastnode = tail->prev;
                mp.erase(lastnode->key);
                deleteNode(lastnode);
            }

            mp[key] = new Node(key,value);
            addNode(mp[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */