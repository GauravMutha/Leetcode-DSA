class Solution {
public:
    int leastInterval(vector<char>& tasks, int idle) {
        vector<int>hash(26,0);
        priority_queue<int>maxh;
        int k=0,extra=0,ans=0,x=0;
        for(auto &e : tasks) hash[e-'A']++;
        for(auto &e : hash) if(e) maxh.push(e);
        
        while(maxh.size()){
            vector<int>temp;
            k=min(idle+1,(int)maxh.size());
            for(int i=0;i<k;i++) temp.push_back(maxh.top()) , maxh.pop();
            for(int i=0;i<temp.size();i++) if(--temp[i]>0) maxh.push(temp[i]);
            extra=(maxh.empty()) ? 0 : idle+1-k;
            ans+=(k+extra);
        }
        
        return ans+maxh.size();
    }
};