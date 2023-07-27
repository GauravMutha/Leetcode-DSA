//Memoization
//From first index
class Solution {
public:
    
    int helper(int ind,int preInd,vector<int>& nums,vector<vector<int>>& dp){
        
        if(ind>=nums.size()) return 0;
        
        if(dp[ind][preInd+1]!=-1) return dp[ind][preInd+1];
        
        int pick=0;
        
        if(preInd==-1 || nums[ind]>nums[preInd]) pick=1+helper(ind+1,ind,nums,dp);
        int notPick=helper(ind+1,preInd,nums,dp);
        
        return dp[ind][preInd+1]=max(pick,notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
        return helper(0,-1,nums,dp);
    }
};