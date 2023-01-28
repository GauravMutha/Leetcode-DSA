//Priority Queue maxheap
class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>maxh;
        int ans=0 , x1=0,x2=0;
        for(auto &e: amount) if(e) maxh.push(e);
        
        while(maxh.size()>1){
            x1=maxh.top() , maxh.pop();
            x2=maxh.top() , maxh.pop();
            ans++;
            if(--x1>0) maxh.push(x1);
            if(--x2>0) maxh.push(x2);
        }
        if(!maxh.empty()) ans+=maxh.top(), maxh.pop();
        return ans;
    }
};