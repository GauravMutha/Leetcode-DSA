//Tabulation- from last to first- corresponding to first memoization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res=INT_MAX,n=matrix.size();
        
        if(n==1) return matrix[0][0];
        
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        // initialising dp
        for(int i=0;i<n;i++) dp[n-1][i]=matrix[n-1][i];
        
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int down=dp[i+1][j];
                int diaLeft=(j==0)?INT_MAX:dp[i+1][j-1];
                int diaRight=(j==(n-1))?INT_MAX:dp[i+1][j+1];
                
                dp[i][j]=matrix[i][j]+min(down,min(diaLeft,diaRight));
                
                //collecting our answer from lastly processed row(0th row)
                if(i==0) res=min(res,dp[0][j]);
            }
        }
        return res;
    }
};