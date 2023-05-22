//Tabulation+Space Optimisation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacles) {
        int m=obstacles.size(),n=obstacles[0].size();
        vector<int>dp(n,0); 
        
        //If the very first cell has obstacle,no other cell can be reached
        dp[0]=!obstacles[0][0];
        if(dp[0]==0) return 0;
        
        for(int j=1;j<n;j++){
            if(dp[j-1]==0) dp[j]=0;
            else dp[j]=!obstacles[0][j];
        }
        
        for(int i=1;i<m;i++){
            vector<int>tempDP(n,0);
            for(int j=0;j<n;j++){
                if(obstacles[i][j]==1) continue;
                if(j==0) tempDP[0]=(dp[0]==0)?0:!obstacles[i][0];
                else tempDP[j]=tempDP[j-1]+dp[j];
            }
            dp=move(tempDP);
        }
        
        return dp[n-1];
    }
};