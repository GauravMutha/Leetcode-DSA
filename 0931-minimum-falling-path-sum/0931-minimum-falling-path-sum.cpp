//Space optimisation- corresponding to first Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res=INT_MAX,n=matrix.size();
        
        if(n==1) return matrix[0][0];
        
        vector<int>dp(n,0);
        
        // initialising dp
        for(int i=0;i<n;i++) dp[i]=matrix[n-1][i];
        
        
        for(int i=n-2;i>=0;i--){
            vector<int>tempDP(n,0);
            for(int j=0;j<n;j++){
                int down=dp[j];
                int diaLeft=(j==0)?INT_MAX:dp[j-1];
                int diaRight=(j==(n-1))?INT_MAX:dp[j+1];
                
                tempDP[j]=matrix[i][j]+min(down,min(diaLeft,diaRight));
                
                //collecting our answer from lastly processed row(0th row)
                if(i==0) res=min(res,tempDP[j]);
            }
            dp=move(tempDP);
        }
        return res;
    }
};