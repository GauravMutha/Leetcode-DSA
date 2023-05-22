//Tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacles) {
        int m=obstacles.size(),n=obstacles[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0)); 
        
        //If the very first cell has obstacle,no other cell can be reached
        dp[0][0]=!obstacles[0][0];
        if(dp[0][0]==0) return 0;
        
        /*here we pre-process DP so that first row and 
        column get defined about what they will return
        based on obstacles array.Also such preprocessing
        helps in base cases for memoization approach too
        which was in the last submission*/
        for(int j=1;j<n;j++){
            if(dp[0][j-1]==0) dp[0][j]=0;
            else dp[0][j]=!obstacles[0][j];
        }
        
        for(int i=1;i<m;i++){
            if(dp[i-1][0]==0) dp[i][0]=0;
            else dp[i][0]=!obstacles[i][0];
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacles[i][j]==1) continue;
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};