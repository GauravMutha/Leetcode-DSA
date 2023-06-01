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
            
            /*since we have sorted the array
            if the sum is greater when any
            nums[i] is added , we can break*/
            
            if((sum+nums[i]) > target) break;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        int sum=0;
        helper(0,sum,ds,nums,target);
        return res;
    }
};