//Space Optimisation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size() ,n= grid[0].size();
        vector<int>dp(n,0);
        
        dp[0]=grid[0][0];
        for(int j=1;j<n;j++) dp[j]=grid[0][j]+dp[j-1];
        
        for(int i=1;i<m;i++){
            vector<int>tempDP(n,0);
            for(int j=0;j<n;j++){
                if(j==0) tempDP[0]=grid[i][0]+dp[0];
                else tempDP[j]=grid[i][j]+min(dp[j],tempDP[j-1]);
            }
            dp=move(tempDP);
        }
        
        return dp[n-1];
    }
};