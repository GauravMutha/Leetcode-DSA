//Comparator
// And priority queue minheap
typedef pair<int,int> p;
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int cap) {
        priority_queue<p,vector<p>,greater<p>>minh;
        
        for(auto &e : trips) minh.push({e[2],e[0]});
        sort(begin(trips),end(trips),[](const auto &a,const auto &b){
            return a[1]<b[1];
        });
        
        int curr=trips[0][0];
        if(curr>cap) return false;
        
        for(int i=1;i<trips.size();i++){
            int passenger=trips[i][0] , pickup=trips[i][1];
            curr+=passenger;
            while(minh.top().first<=pickup) 
                curr-=minh.top().second , minh.pop();
            
            if(curr>cap) return false;
        }
        
        return true;
    }
};