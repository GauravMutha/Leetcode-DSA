//simplified memoization
class Solution {
public:
    int helper(int m,int n,vector<vector<int>>& dp,vector<vector<int>>& obstacles){
        if( (m>=0 && n>=0 && obstacles[m][n]==1) || (m<0 || n<0) ) 
            return 0;
        if(m==0 && n==0) return 1;
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        int viaTop=helper(m-1,n,dp,obstacles);
        int viaLeft=helper(m,n-1,dp,obstacles);
        
        return dp[m][n]=(viaLeft+viaTop);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacles) {
        int m=obstacles.size(),n=obstacles[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1)); 
        
        return helper(m-1,n-1,dp,obstacles);
    }
};