//Somewhat follows "subset sum equals k",but here there is no notPick condition
//Simple memoization
//Using offset to handle negative indexes
class Solution {
public:
    int helper(int ind,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(ind<0) return (target==0);
        
        if(dp[ind][target+20000]!=-1)
            return dp[ind][target+20000];
        
        int pickPos=0,pickNeg=0;
        
        pickPos=helper(ind-1,target-nums[ind],nums,dp);
        pickNeg=helper(ind-1,target+nums[ind],nums,dp);
        
        return dp[ind][target+20000]=(pickPos+pickNeg);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(21,vector<int>(40001,-1));
        return helper(n-1,target,nums,dp);
    }
};