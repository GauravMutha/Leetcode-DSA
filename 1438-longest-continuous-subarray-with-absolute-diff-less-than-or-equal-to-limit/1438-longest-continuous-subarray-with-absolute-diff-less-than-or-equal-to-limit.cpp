//Using priority queues
typedef pair<int,int>p;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<p>maxh;
        priority_queue<p,vector<p>,greater<p>>minh;
        int l=0,r=0,res=INT_MIN , n=nums.size();
        
        while(r<n){
            maxh.push({nums[r],r});
            minh.push({nums[r],r});
            
            while(minh.top().second < l)
                minh.pop();
            while(maxh.top().second < l)
                maxh.pop();
            
            if(maxh.top().first - minh.top().first <= limit){
                res=max(res,r-l+1);
                r++;
            }
            else l++ , r++;
        }
        
        return res;
    }
};