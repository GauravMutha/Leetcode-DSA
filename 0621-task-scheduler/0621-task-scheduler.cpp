class Solution {
public:
    int leastInterval(vector<char>& tasks, int idle) {
        priority_queue<int>maxh;
        vector<int>hash(26,0);
        int k=0,extra=0,ans=0;
        
        for(auto c :tasks) hash[c-'A']++;
        for(int i=0;i<hash.size();i++) if(hash[i]) maxh.push(hash[i]);
        
        while(maxh.size()){
            k=min(idle+1,(int)maxh.size());
            
            vector<int>temp;
            for(int i=0;i<k;i++) 
                temp.push_back(maxh.top()) , maxh.pop();
            for(int i=0;i<temp.size();i++) 
                if((temp[i]-1)>0) maxh.push(temp[i]-1);
            
            extra=(maxh.empty())?0:idle+1-k;
            ans+=(k+extra);
        }
        
        return ans;
    }
};