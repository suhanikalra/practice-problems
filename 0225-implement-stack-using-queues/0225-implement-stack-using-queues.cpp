class MyStack {
public:
queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        auto size= q.size();
        while(size-1){
            auto ele= q.front();
            q.pop();
            q.push(ele);
            size--;
        }
    }
    
    int pop() {
        auto ans=q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        auto ans=q.front();
        
        return ans;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */