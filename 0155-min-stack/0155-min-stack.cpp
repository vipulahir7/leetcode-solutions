class MinStack {
public:
    stack<int> ds,mini;
    MinStack() {
        
    }
    
    void push(int val) {
        ds.push(val);
        if(mini.empty() || mini.top()>=val) mini.push(val);
    }
    
    void pop() {
        if(ds.top() == mini.top()) mini.pop();
        ds.pop();
    }
    
    int top() {
        return ds.top();
    }
    
    int getMin() {
        return mini.top();
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