//memoization
class Solution {
public:
    bool helper(int ind, int target,vector<vector<int>>& dp,vector<int>& nums){
        if(target==0) return true;
        if(ind==0) return (nums[0]==target);
    
        if(dp[ind][target]!=-1) return dp[ind][target];
    
        bool notPick= helper(ind-1,target,dp,nums);
        bool pick=false;
        if(nums[ind]<=target) pick= helper(ind-1,target-nums[ind],dp,nums);
    
        return dp[ind][target]= (pick || notPick);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total%2) return false; //two equal integers cannot add upto an odd number
        vector<vector<int>>dp(n,vector<int>(total/2+1,-1));
        
        return helper(n-1,total/2,dp,nums);
    }
};