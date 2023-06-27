class MinStack {
private:
    vector<int>minVals , mainSt;
public:
    MinStack() {}
    
    void push(int val) {
        mainSt.push_back(val);
        if(minVals.size()==0 || minVals.back()>=val) minVals.push_back(val);
    }
    
    void pop() {
        if(mainSt.back()==minVals.back()) minVals.pop_back();
        mainSt.pop_back();
    }
    
    int top() {
        return mainSt.back();
    }
    
    int getMin() {
        return minVals.back();
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