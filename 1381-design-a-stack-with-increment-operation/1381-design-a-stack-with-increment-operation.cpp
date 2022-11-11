class CustomStack {
private:
    int *S;
    int size=0;
    int top;
public:
    CustomStack(int maxSize) {
        if(maxSize>1000) return;
        size=maxSize;
        S=new int[size];
        top=-1;
    }
    
    void push(int x) {
        if(top==size-1) return;
        top++;
        S[top]=x;
    }
    
    int pop() {
        if(top==-1) return -1;
        int popped_element=S[top];
        top--;
        return popped_element;
    }
    
    void increment(int k, int val) {
       for(int i=0;i<k && i<=top;i++)
           S[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */