//Memoization
class Solution {
public:
    int helper(int ind,int k, vector<int> &nums,vector<int>& dp){
        
        if(ind==nums.size()) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int maxSum=INT_MIN , maxVal=INT_MIN;
        
        for(int i=ind;i<(ind+k) && i<nums.size();i++){
            
            maxVal=max(nums[i],maxVal);
            
            int sum=(i-ind+1)*maxVal+helper(i+1,k,nums,dp);
            
            maxSum=max(sum,maxSum);
        }
        
        return dp[ind]=maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>dp(n,-1);
        
        return helper(0,k,nums,dp);
    }
};