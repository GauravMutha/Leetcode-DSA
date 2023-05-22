//memoization
class Solution {
public:
    int helper(int m,int n,vector<vector<int>>& dp,vector<vector<int>>& obstacles){
        if(dp[m][n]!=-1) return dp[m][n];
        
        if(obstacles[m][n]==1) return 0;
        
        int viaTop=helper(m-1,n,dp,obstacles);
        int viaLeft=helper(m,n-1,dp,obstacles);
        
        return dp[m][n]=(viaLeft+viaTop);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacles) {
        int m=obstacles.size(),n=obstacles[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1)); 
        
        //If the very first cell has obstacle,no other cell can be reached
        dp[0][0]=!obstacles[0][0];
        if(dp[0][0]==0) return 0;
        
        /*here we pre-process DP so that first row and 
        column get defined about what they will return
        .It helps to handle the base cases in recursion,too*/
        for(int j=1;j<n;j++){
            if(dp[0][j-1]==0) dp[0][j]=0;
            else dp[0][j]=!obstacles[0][j];
        }
        
        for(int i=1;i<m;i++){
            if(dp[i-1][0]==0) dp[i][0]=0;
            else dp[i][0]=!obstacles[i][0];
        }
        
        return helper(m-1,n-1,dp,obstacles);
    }
};