//Re//
//Using bit manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        
        for(int x=0;x<pow(2,n);x++){
            vector<int>ds;
            for(int i=0;i<n;i++)
                if(x&(1<<i)) ds.push_back(nums[i]);
            
            ans.push_back(ds);
        }
        return ans;
    }
};