//Tabulation- from first to last- corresponding to second memoization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res=INT_MAX,n=matrix.size();
        
        if(n==1) return matrix[0][0];
        
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        // initialising dp
        for(int i=0;i<n;i++) dp[0][i]=matrix[0][i];
        
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int down=dp[i-1][j];
                int diaLeft=(j==0)?INT_MAX:dp[i-1][j-1];
                int diaRight=(j==(n-1))?INT_MAX:dp[i-1][j+1];
                
                dp[i][j]=matrix[i][j]+min(down,min(diaLeft,diaRight));
                
                //collecting our answer from lastly processed row(0th row)
                if(i==(n-1)) res=min(res,dp[n-1][j]);
            }
        }
        return res;
    }
};