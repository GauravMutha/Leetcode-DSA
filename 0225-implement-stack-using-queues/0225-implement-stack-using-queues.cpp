//Using two queues
class MyStack {
private:
    queue<int>q1,q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.size()==0) q1.push(x);
        else{
            q2.push(x);
            while(q1.size()) q2.push(q1.front()) , q1.pop();
            swap(q1,q2);
        }
    }
    
    int pop() {
        int res=q1.front();
        q1.pop();
        return res;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.size()==0;
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