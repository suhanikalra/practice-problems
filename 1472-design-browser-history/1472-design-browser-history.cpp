class Node{
    public:
string url;
Node* next;
Node* prev;

Node(string str){
    next= NULL;
    prev= NULL;
    url= str;
}
};

class BrowserHistory {
public:
Node* curr;
    BrowserHistory(string homepage) {
        curr= new Node(homepage);
        
    }
    
    void visit(string url) {
        curr->next= new Node(url);
        curr->next->prev= curr;
        curr= curr->next;
    }
    
    string back(int steps) {
        while(steps--){
            if( curr->prev){
        curr= curr->prev;
            }
            

        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps--){
            if( curr->next){
        curr= curr->next;
            }
            

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