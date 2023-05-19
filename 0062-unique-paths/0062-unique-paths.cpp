//Tabulation - Space Optimisation
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        
        //initialising of the dp
        vector<int>dp(n,1);
        dp[0]=0;
        
        for(int i=1;i<m;i++){
            vector<int>tempDP(n,1);
            for(int j=1;j<n;j++){
               tempDP[j]=tempDP[j-1]+dp[j];
            }
            dp=move(tempDP);
        }
        
        return dp[n-1];
    }
};