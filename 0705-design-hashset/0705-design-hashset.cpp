class Node{
    public:
        Node* next;
        Node* prev;
        int key;

        Node(int key){
            this->key= key;
            next=NULL;
            prev=NULL;

        }
    
};

class MyHashSet {
public:
vector<Node*>table;
    MyHashSet() {
        table.resize(1000,NULL);
    }
    
    void add(int key) {
    int modVal = key % 1000;

    Node* node = table[modVal];

    
    while(node){
        if(node->key == key)
            return;
        node = node->next;
    }

    Node* newNode = new Node(key);
    newNode->next = table[modVal];

    if(table[modVal])
        table[modVal]->prev = newNode;

    table[modVal] = newNode;
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
    
    bool contains(int key) {
        int modval = key % 1000;
        Node* node = table[modval];

        while(node){
            if(node->key == key){
               
                return true;
            }
            node = node->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */