//Backtracking style memoization
class Solution {
public:
    int helper(int ind,int total,vector<int>& nums,vector<int>& dp){
        if(ind>=nums.size())
            return 0;
        int sum=0;
        
        for(int i=ind;i<nums.size();i++){
            if(dp[i]==-1){
                total=helper(i+2,total,nums,dp)+nums[i];
                dp[i]=total;
            }
            else total=dp[i];
            
            sum=max(total,sum);
        }
        return sum;
        
    }
    int rob(vector<int>& nums) {
        vector<int>dp(100,-1);
        return helper(0,0,nums,dp);
    }
};