//Priority Queue Max heap
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxh;
        int y=0,x=0;
        for(auto &s : stones) maxh.push(s);
        
        while(maxh.size()>1){
            y=maxh.top() , maxh.pop();
            x=maxh.top() , maxh.pop();
            
            if(x!=y) y-=x , maxh.push(y);
        }
        
        return (maxh.size()) ? maxh.top() : 0;
    }
};