//Somewhat follows "subset sum equals k",but here there is no notPick condition
//Simple memoization
//Using offset to handle negative indexes

//Starting from 0th index
class Solution {
public:
    int helper(int ind,int sum,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(ind==nums.size()){
            return (sum==target);
        }
        
        if(dp[ind][sum+1000]!=-1)
            return dp[ind][sum+1000];
        
        int pickPos=0,pickNeg=0;
        
        pickPos=helper(ind+1,sum+nums[ind],target,nums,dp);
        pickNeg=helper(ind+1,sum-nums[ind],target,nums,dp);
        
        return dp[ind][sum+1000]=(pickPos+pickNeg);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(21,vector<int>(2001,-1));
        return helper(0,0,target,nums,dp);
    }
};