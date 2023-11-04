class Solution {
public:
    int helper(int ind,vector<int>& nums,int target,vector<vector<int>>& dp){
        
        if(target<0) return -1e9;
        if(ind>=nums.size()) return (target==0) ? 0:-1e9;
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        int take=1+helper(ind+1,nums,target-nums[ind],dp);
        int notTake=helper(ind+1,nums,target,dp);
        
        return dp[ind][target]=max(take,notTake);
    }
    
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
        
        int res=helper(0,nums,target,dp);
        
        return (res<=0) ? -1 :res;
    }
};