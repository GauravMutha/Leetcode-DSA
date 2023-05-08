//Backtracking style memoization
//Alternate implementation
class Solution {
public:
    int helper(int ind,vector<int>& nums,vector<int>& dp){
        if(ind>=nums.size())
            return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int pick=helper(ind+2,nums,dp)+ nums[ind];
        int notPick=helper(ind+1,nums,dp);
        
        dp[ind]= max(pick,notPick);
        return max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return helper(0,nums,dp);
    }
};