class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = next = NULL;
    }
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> cacheMap;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);  // dummy head
        tail = new Node(-1, -1);  // dummy tail

        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end())
            return -1;

        Node* node = cacheMap[key];
        int ans = node->val;

        deleteNode(node);
        addNode(node);

        return ans;
    }

    void put(int key, int value) {

        if (cacheMap.find(key) != cacheMap.end()) {
            Node* node = cacheMap[key];
            node->val = value;

            deleteNode(node);
            addNode(node);
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
            addNode(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */