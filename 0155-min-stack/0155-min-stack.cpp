class MinStack {
public:
stack<int>asc;
stack<int>st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
            if(!asc.empty() and asc.top()>=val)asc.push(val);
            if(asc.empty())asc.push(val);
        
    }
    
    void pop() {
        if(!st.empty()){
        int k= st.top();
        st.pop();
        if(!asc.empty() and asc.top()==k)asc.pop();
        }
        
    }
    
    int top() {
       if(!st.empty()) return st.top();
       return 0;
    }
    
    int getMin() {
       if(!asc.empty()) return asc.top();
       return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */