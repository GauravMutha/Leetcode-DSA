class MyCircularQueue {
public:
    int f=0,r=0;
    vector<int>q;
    MyCircularQueue(int k) {
        for(int i=0;i<=k;i++) q.push_back(-1);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        r=(r+1)%q.size();
        q[r]=value;
        
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        f=(f+1)%q.size();
        q[f]=-1;
        
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[(f+1)%q.size()];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[r];
    }
    
    bool isEmpty() {
        return (f==r);
    }
    
    bool isFull() {
        return ((r+1)%q.size()==f);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */