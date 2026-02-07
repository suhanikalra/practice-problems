class BrowserHistory {
public:
class Node{
   public:
    string url;
    Node* next;
    Node* prev; 

    Node(string url){
        this->url= url;
        next=NULL;
        prev=NULL;
    }

};
Node* curr;
    BrowserHistory(string homepage) {
       curr= new Node( homepage);
    }
    
    void visit(string url) {
        Node* temp = new Node(url);
        curr->next= temp;
        temp->prev= curr;
        curr= curr->next;
    }
    
    string back(int steps) {
        while( steps and curr->prev){
            if( steps==0)return curr->url;
            if( curr->prev)curr= curr->prev;
            steps--;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while( steps and curr->next){
            if( steps==0)return curr->url;
            if( curr->next)curr= curr->next;
            steps--;
        }
        return curr->url;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */