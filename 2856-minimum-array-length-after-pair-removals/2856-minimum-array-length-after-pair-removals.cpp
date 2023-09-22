class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int>m;
        for(auto &num : nums) m[num]++;
        priority_queue<int>pq;
        
        for(auto &[num,freq]:m) pq.push(freq);
        
        while(pq.size()>1){
            int freq1=pq.top(); pq.pop();
            int freq2= pq.top(); pq.pop();
            
            freq1--, freq2--;
            
            if(freq1) pq.push(freq1);
            if(freq2) pq.push(freq2);
        }
        return (pq.size()) ? pq.top() :0;  
    }
};