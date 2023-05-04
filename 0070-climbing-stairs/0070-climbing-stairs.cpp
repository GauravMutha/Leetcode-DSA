//Memoization(td) but this time we go from highest stair to lowest one
//k denotes final stair
//TC-->O(n)
//SC-->O(n)

class Solution {
public:
    int helper(vector<int>& dp,int k){
        if(k==1 || k==0) return 1;
        
        if(dp[k]!=-1) return dp[k];
        int oneStep=helper(dp,k-1);
        int twoStep=helper(dp,k-2);
        
        return dp[k]=oneStep+twoStep;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return helper(dp,n);
    }
};