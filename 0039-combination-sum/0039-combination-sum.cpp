class Solution {
public:
    vector<vector<int>>res;
    void helper(int i,int target,vector<int>& ds,vector<int>& nums){
        if(target==0){
            res.push_back(ds);
            return;
        }
        if(i>=nums.size() || target<0) return;
        
        ds.push_back(nums[i]);
        helper(i,target-nums[i],ds,nums);
        ds.pop_back();
        helper(i+1,target,ds,nums);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>ds;
        helper(0,target,ds,nums);
        
        return res;
    }
};