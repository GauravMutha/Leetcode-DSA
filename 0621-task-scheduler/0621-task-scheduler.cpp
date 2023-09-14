class Solution {
public:
    int leastInterval(vector<char>& tasks, int idle) {
        int ans=0;
        vector<int>hash(26,0);
        priority_queue<int>maxh;
        
        for(auto c : tasks) hash[c-'A']++;
        for(int i=0;i<26;i++) if(hash[i]) maxh.push(hash[i]);
        
        while(maxh.size()){
            int k=min(idle+1,(int)maxh.size());
            
            vector<int>temp;
            for(int i=0;i<k;i++) 
                temp.push_back(maxh.top()),maxh.pop();
            for(int i=0;i<k;i++) if(temp[i]-1) maxh.push(temp[i]-1);
            
            int extra=maxh.empty()?0:idle+1-k;
            ans+=(k+extra);
        }
        
        return ans;
    }
};