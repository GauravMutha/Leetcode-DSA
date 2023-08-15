class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m=matrix.size() , n=matrix[0].size(),side=0;
        vector<vector<int>>dp(m,vector<int>(n,0));
        
        for(int j=0;j<n;j++) 
            dp[0][j]=matrix[0][j]-'0',side=max(side,matrix[0][j]-'0');
        for(int i=0;i<m;i++) 
            dp[i][0]=matrix[i][0]-'0',side=max(side,matrix[i][0]-'0');
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]=='0') dp[i][j]=0;
                else dp[i][j]=min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]})+1;
                
                side=max(side,dp[i][j]);
            }
        }
        
        return side*side;
    }
};