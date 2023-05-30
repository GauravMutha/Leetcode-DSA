//Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n=tri.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        //Initialise the last row of dp
        for(int i=0;i<n;i++) dp[n-1][i]=tri[n-1][i];
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                dp[i][j]=tri[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        
        return dp[0][0];
    }
};