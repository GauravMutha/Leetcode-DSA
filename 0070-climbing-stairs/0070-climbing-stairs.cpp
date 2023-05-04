//Tabulation(bottom up)
//solving from lowest subproblem (final stair =0) to higher subproblems
//TC-->O(n)
//SC-->O(n)

class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        
        return dp.back();
    }
};