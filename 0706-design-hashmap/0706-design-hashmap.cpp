class Node{
public:
    Node* next;
    Node* prev;
    int key;
    int val;

    Node(int k,int v){
        key = k;
        val = v;
        next = NULL;
        prev = NULL;
    }
};

class MyHashMap {
public:
    vector<Node*> table;

    MyHashMap() {
        table.resize(1000,NULL);
    }
    
    void put(int key, int value) {
        int modval = key % 1000;

        Node* node = table[modval];

        while(node){
            if(node->key == key){
                node->val = value;
                return;
            }
            node = node->next;
        }

        Node* newNode = new Node(key,value);
        newNode->next = table[modval];

        if(table[modval])
            table[modval]->prev = newNode;

        table[modval] = newNode;
    }
    
    int get(int key) {
        int modval = key % 1000;
        Node* node = table[modval];

        while(node){
            if(node->key == key)
                return node->val;
            node = node->next;
        }

        return -1;
    }
    
    void remove(int key) {
        int modval = key % 1000;
        Node* node = table[modval];

        while(node){
            if(node->key == key){

                if(node->prev)
                    node->prev->next = node->next;
                else
                    table[modval] = node->next;

                if(node->next)
                    node->next->prev = node->prev;

                delete node;
                return;
            }

            node = node->next;
        }
    }
};