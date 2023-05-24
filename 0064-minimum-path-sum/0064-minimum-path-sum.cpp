//Memoization
class Solution {
public:
    int helper(int m,int n,vector<vector<int>>& dp,vector<vector<int>>& grid){
        if(m<0 || n<0) return INT_MAX;
        if(m==0 && n==0) return grid[m][n];
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        int viaTop=helper(m-1,n,dp,grid);
        int viaLeft=helper(m,n-1,dp,grid);
        
        int minRet=min(viaTop,viaLeft);
        
        return dp[m][n]=(grid[m][n]+minRet);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size() ,n= grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,dp,grid);
    }
};