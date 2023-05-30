//Space optimisation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n=tri.size();
        vector<int>dp(n,0);
        //Initialise the dp with the last row of triangle
        for(int i=0;i<n;i++) dp[i]=tri[n-1][i];
        
        for(int i=n-2;i>=0;i--){      
            vector<int>temp(i+1,0);
            for(int j=i;j>=0;j--){
                temp[j]=tri[i][j]+min(dp[j],dp[j+1]);
            }
            dp.pop_back();
            dp=move(temp);
        }
        
        return dp[0];
    }
};