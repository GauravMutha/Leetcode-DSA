//Memoization(td)
//TC-->O(n)
//SC-->O(n)

class Solution {
public:
    int helper(vector<int>& dp,int step,int finalStair){
        if(step==finalStair) return 1;
        if(step>finalStair) return 0;
        
        if(dp[step]!=-1) return dp[step];
        int oneStep=helper(dp,step+1,finalStair);
        int twoStep=helper(dp,step+2,finalStair);
        
        return dp[step]=oneStep+twoStep;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return helper(dp,0,n);
    }
};