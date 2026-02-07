class MyHashMap {
public:
    static const int MOD = 1009;
    struct Node {
        int key, val;
        Node* next;
        Node(int k, int v) : key(k), val(v), next(NULL) {}
    };

    vector<Node*> table;

    MyHashMap() { table.assign(MOD, nullptr); }
    int hash(int key) { return key % MOD; }

    void put(int key, int value) {
        int idx = key % MOD;
        Node* row = table[key % MOD];
        Node* curr = row;
        while (curr) {
            if (curr->key == key) {
                curr->val = value;
                return;
            }
            curr = curr->next;
        }

        Node* node = new Node(key, value);
        node->next = table[idx];
        table[idx] = node;
    }

    int get(int key) {
        Node* row = table[key % MOD];
        Node* curr = row;
        while (curr) {
            if (curr->key == key) {
                return curr->val;
            }
            curr = curr->next;
        }
        return -1;
    }

    void remove(int key) {
        int idx = key % MOD;
        Node* curr = table[idx];
        Node* prev = nullptr;

        while (curr) {
            if (curr->key == key) {
                if (prev == nullptr) {
                    table[idx] = curr->next;
                } else {

                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};
