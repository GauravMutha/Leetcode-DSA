class ExamRoom {
private:
    int capacity;
    set<int>seats; 
public:
    ExamRoom(int n) {
        capacity=n;
    }
    
    int seat() {
        int curr=0 , dist=0;
        if(!seats.empty()){
            auto it=seats.begin();
            dist=*it;
            
            if(dist==0) it++;
            
            while(it!=seats.end()){
                int midDist=(*it - *prev(it))/2;
                if(midDist > dist){
                    dist=midDist;
                    curr= *prev(it)+dist;
                }
                it++;
            }
            
            if((capacity-1 - *(seats.rbegin())) > dist) curr=capacity-1;
        }
        seats.insert(curr);
        return curr;
    }
    
    void leave(int p) {
        seats.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */