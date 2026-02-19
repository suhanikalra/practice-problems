class Node {
public:
    Node* next;
    Node* prev;
    int key, val;

    Node(int k, int v) {
        key = k;
        val = v;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    int cap;
    Node* head;
    Node* tail;

    void insertAtHead(Node* node) {
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto node = mp[key];
        deleteNode(node);
        insertAtHead(node);
        return node->val;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];
            node->val = value;

            deleteNode(node);
            insertAtHead(node);
        } else {

            if (mp.size() == cap) {

                Node* lru = tail->prev;
                mp.erase(lru->key);
                deleteNode(lru);
                delete lru;
            }

            Node* newNode = new Node(key, value);
            mp[key] = newNode;
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