class MyHashMap {
public:
    struct Node {
        int key, val;
        Node* next;
        Node(int k, int v) : key(k), val(v), next(NULL) {}
    };

    Node* head;

    MyHashMap() {
        head = NULL;
    }

    void put(int key, int value) {
        Node* curr = head;

        while (curr) {
            if (curr->key == key) {
                curr->val = value;
                return;
            }
            curr = curr->next;
        }

        Node* temp = new Node(key, value);
        temp->next = head;
        head = temp;
    }

    int get(int key) {
        Node* curr = head;
        while (curr) {
            if (curr->key == key)
                return curr->val;
            curr = curr->next;
        }
        return -1;
    }

    void remove(int key) {
        Node* curr = head;
        Node* prev = NULL;

        while (curr) {
            if (curr->key == key) {
                if (prev)
                    prev->next = curr->next;
                else
                    head = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};
