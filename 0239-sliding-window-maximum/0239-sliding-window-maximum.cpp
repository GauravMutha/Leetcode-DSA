//using deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        deque<int>q;
        int l=0,r=0,n=nums.size();
        for(r=0;r<n;r++){
            
            while(q.size() && q.back()<nums[r]) q.pop_back();
            q.push_back(nums[r]);
            
            if((r-l+1)<k) continue;
            
            res.push_back(q.front());
            
            if(q.front()==nums[l]) q.pop_front();
            l++;
        }
        
        return res;
    }
};