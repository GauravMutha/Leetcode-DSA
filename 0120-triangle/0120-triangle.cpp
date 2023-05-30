//Memoization
class Solution {
public:
    int helper(int row,int col,vector<vector<int>>&dp,vector<vector<int>>& tri){
        if(row==(tri.size()-1)) return tri[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int down=tri[row][col]+helper(row+1,col,dp,tri);
        int diaRight=tri[row][col]+helper(row+1,col+1,dp,tri);
        return dp[row][col]=min(down,diaRight);
    }
    int minimumTotal(vector<vector<int>>& tri) {
        int n=tri.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(0,0,dp,tri);
    }
};