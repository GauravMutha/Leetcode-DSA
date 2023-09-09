//Memoization
class Solution {
public:
    int helper(vector<int>& nums,int target,vector<int>& dp){
        
        if(target==0) return 1;
        if(target<0) return 0;
        
        if(dp[target]!=-1) return dp[target];
        
        int count=0;
        for(int i=0;i<nums.size();i++){
            
            count+=helper(nums,target-nums[i],dp);
            if((target-nums[i])<0) break;
        }
        
        return dp[target]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>dp(target+1,-1);
        return helper(nums,target,dp);
    }
};