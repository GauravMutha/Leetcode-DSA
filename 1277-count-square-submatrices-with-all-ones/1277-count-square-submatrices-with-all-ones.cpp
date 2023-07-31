//Simple tabulation

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int m=matrix.size() , n=matrix[0].size(), res=0;
        
        vector<vector<int>>dp(m,vector<int>(n,0));
        
        //initialising dp
        for(int j=0;j<n;j++) dp[0][j]=matrix[0][j] , res+=dp[0][j];
        for(int i=0;i<m;i++) dp[i][0]=matrix[i][0] , res+=dp[i][0];
        //in case we added first cell twice if it was 1, we have to subtract it
        if(matrix[0][0]==1) res--;
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0) continue;
                else dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
                
                res+=dp[i][j];
            }
        }
        
        return res;
        
    }
};