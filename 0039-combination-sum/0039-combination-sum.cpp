class Solution {
public:
    vector<vector<int>>res;
    void helper(int ind,int& sum,vector<int>& ds,vector<int>& nums,int target){
        if(sum>=target){
            if(sum==target) res.push_back(ds);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            ds.push_back(nums[i]);
            sum+=nums[i];
            helper(i,sum,ds,nums,target);
            ds.pop_back();
            sum-=nums[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        //No sorting
        vector<int>ds;
        int sum=0;
        helper(0,sum,ds,nums,target);
        return res;
    }
};