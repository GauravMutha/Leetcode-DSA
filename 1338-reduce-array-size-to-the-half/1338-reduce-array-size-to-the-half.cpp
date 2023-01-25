//Priority Queue +Map
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int removed=0,sz=arr.size(),res=0;
        priority_queue<int>maxh;
        unordered_map<int,int>m;
        
        for(auto e : arr) m[e]++;
        
        //just a reverse sort
        for(auto &[num,freq]: m)
            maxh.push(freq);
        while(!maxh.empty()){
            removed+=maxh.top(), res++;
            if(removed>=(sz/2)) return res;
            maxh.pop();
        }
        return removed;
    }
};