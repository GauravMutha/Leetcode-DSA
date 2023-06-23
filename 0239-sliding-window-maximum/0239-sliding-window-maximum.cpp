//Using ordered_map
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        int l=0 ,r=0 , n=nums.size();
        map<int,int>m;
        
        for(r=0;r<n;r++){
            
            m[nums[r]]++;
            if((r-l+1)<k) continue;
            
            res.push_back(m.rbegin()->first);
            
            m[nums[l]]--;
            if(m[nums[l]]==0) m.erase(nums[l]);
            l++;
        }
        
        return res;
    }
};