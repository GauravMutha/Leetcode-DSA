//Memoization- reverse direction(from last to first row)
class Solution {
public:
    int helper(int row,int col,vector<vector<int>>& dp,vector<vector<int>>& matrix){
        if(col>=matrix.size() || col<0) return INT_MAX;
        if(row==0) return matrix[row][col];
        
        if(dp[row][col]!=-1) return dp[row][col];
        
        int down =helper(row-1,col,dp,matrix);
        int diaLeft =helper(row-1,col-1,dp,matrix);
        int diaRight =helper(row-1,col+1,dp,matrix);
        
        return dp[row][col]=matrix[row][col]+min(down,min(diaLeft,diaRight));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res=INT_MAX,n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            int retValue=helper(n-1,i,dp,matrix);
            res=min(res,retValue);
        }
        return res;
    }
};