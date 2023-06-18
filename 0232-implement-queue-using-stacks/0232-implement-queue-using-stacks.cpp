class MyQueue {
private:
    stack<int>st1,st2;
public:
    MyQueue() {}
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int x=this->peek();
        st2.pop();
        return x;
    }
    
    int peek() {
        if(st2.empty()){
            while(st1.size()) 
                st2.push(st1.top()) , st1.pop();
        }
        int x=st2.top();
        return x;
    }
    
    bool empty() {
        return (st1.empty() && st2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */