typedef pair<int,int>pii; 
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int cap) {
        
        sort(begin(trips),end(trips),[](const auto &a,const auto &b){
            return a[1]<b[1];
        });
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        
        int curr=trips[0][0];
        pq.push({trips[0][2],trips[0][0]});
        if(curr>cap) return false;
        
        for(int i=1;i<trips.size();i++){
            while(pq.size() && trips[i][1]>=pq.top().first) 
                curr-=pq.top().second,pq.pop();
            
            curr+=trips[i][0];
            pq.push({trips[i][2],trips[i][0]});
            if(curr>cap) return false;
        }
        return true;
    }
};