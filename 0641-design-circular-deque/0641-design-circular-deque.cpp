class MyCircularDeque {
public:
    int f,r,count,total;
    vector<int>q;
    MyCircularDeque(int k) {
       q.resize(k);
        r=0,f=k-1,count=0,total=k;
    }
    
    bool insertFront(int value) {
        if(count==total) return false;
        q[f]=value;
        f=(f-1+total)%total;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if(count==total) return false;
        q[r]=value;
        r=(r+1)%total;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if(count==0) return false;
        f=(f+1)%total;
        count--;
        return true;
    }
    
    bool deleteLast() {
        if(count==0) return false;
        r=(r-1+total)%total;
        count--;
        return true;
    }
    
    int getFront() {
        if(count==0) return -1;
        return q[(f+1+total)%total];
    }
    
    int getRear() {
        if(count==0) return -1;
        return q[(r-1+total)%total];
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
        return count==total;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */