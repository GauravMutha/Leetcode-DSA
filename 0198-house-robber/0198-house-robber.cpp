//Striver sheet
class Solution {
public:
    int helper(int ind,vector<int>& nums,vector<int>& dp){
        if(ind>=nums.size()) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int pick=nums[ind]+helper(ind+2,nums,dp);
        int notPick=helper(ind+1,nums,dp);
        
        return dp[ind]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+2,0);
        
        for(int ind=n-1;ind>=0;ind--){
            int pick=nums[ind]+dp[ind+2];
            int notPick=dp[ind+1];
            
            dp[ind]=max(pick,notPick);
        }
        
        return dp[0];
    }
};