class Node{
   public:
    Node* next;
    Node* prev;
    int val;

    Node(int v){
        this->val= v;
        this->next= NULL;
        this->prev= NULL;
    }

};

class MyCircularDeque {
public:
Node* head;
Node* tail;
int capacity;int count=0;
    MyCircularDeque(int k) {
        capacity= k;
        head= new Node(-1);
        tail= new Node(-1);
        head->next= tail;
        tail->prev= head;
    }
    
    bool insertFront(int value) {
        if( count==capacity)return false;
        auto temp=head->next;
        Node* node= new Node(value);
        node->next= temp;
        temp->prev= node;
        node->prev= head;
        head->next= node;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if( capacity==count)return false;
        auto temp= tail->prev;
        Node* node= new Node(value);
        node->next= tail;
        node->prev= temp;
        temp->next= node;
        tail->prev= node;
        count++;
        return true;
        
        
    }
    
    bool deleteFront() {
        if(head->next!= tail){
            head->next= head->next->next;
            head->next->prev= head;
            count--;
            return true;
        }
        return false;
        
    }
    
    bool deleteLast() {
        if( tail->prev!= head){
            tail->prev= tail->prev->prev;
            tail->prev->next= tail;
            count--;
            return true;
        }
        return false;
    }
    
    int getFront() {
        return head->next->val;
        
    }
    
    int getRear() {
        return tail->prev->val;
        
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
        return capacity==count;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */