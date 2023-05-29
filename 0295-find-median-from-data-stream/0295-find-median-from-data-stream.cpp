//using two heaps
class MedianFinder {
private:
    priority_queue<int,vector<int>,greater<int>>rh;
    priority_queue<int>lh;
    int total=0;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        total++;
        lh.push(num);
        if(lh.size() > (total/2)){
            int poppedNum=lh.top();
            lh.pop();
            rh.push(poppedNum);
        }
        if(lh.size()>0 && rh.size()>0 && lh.size()==rh.size() && lh.top()>rh.top()){
            int l=lh.top() , r=rh.top();
            lh.pop() , rh.pop();
            lh.push(r) , rh.push(l);
        }
    }
    
    double findMedian() {
        if(total==1) return lh.top();
        if(total%2) return rh.top();
        
        return ((double)lh.top()+(double)rh.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */