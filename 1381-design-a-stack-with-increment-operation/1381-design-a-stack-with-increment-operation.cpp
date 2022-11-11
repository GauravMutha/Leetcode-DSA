//LEE'S TRICK FOR LAZY INCREMENT THAT MAKES THE SOLUTION O(1)
class CustomStack {
private:
    vector<int>inc,stack;
    int n=0;
public:
    CustomStack(int maxSize) {
        n=maxSize;
    }
    
    void push(int x) {
        if(n==stack.size()) return;
        stack.push_back(x);
        inc.push_back(0);
    }
    
    int pop() {
        int i=stack.size()-1;
        if(i<0) return -1;
        if(i>0) inc[i-1]+=inc[i];
        int num=stack[i]+inc[i];
        inc.pop_back();
        stack.pop_back();
        return num;
    }
    
    void increment(int k, int val) {
        int i=min(k,(int)stack.size())-1;
        if(i>=0)inc[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */