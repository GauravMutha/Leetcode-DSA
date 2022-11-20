class MinStack {
private:
    stack<int>st,mini;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(mini.empty() || mini.top()>=val) mini.push(val);
    }
    
    void pop() {
        int ans=st.top();
        st.pop();
        if(ans==mini.top()) mini.pop();
    }
    
    int top() {
        return st.top(); 
    }
    
    int getMin() {
        return mini.top();
    }
};
//2 stacks
//SC--> O(n)
//TC-->O(1) for all operations

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */