class Solution {
public:
    vector<vector<int>> res;
    void helper(int ind,vector<int>& ds,vector<int>& nums,int target){
        if(target<=0){
            if(target==0) res.push_back(ds);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            target-=nums[i];
            helper(i+1,ds,nums,target);
            target+=nums[i];
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        helper(0,ds,nums,target);
        return res;
    }
};