//Tabulation
class Solution {
public:
    int minDistance(string s1, string s2) {
        
        int n=s1.size() , m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        //initialising dp
        for(int ind1=0;ind1<=n;ind1++) dp[ind1][0]=ind1;
        for(int ind2=0;ind2<=m;ind2++) dp[0][ind2]=ind2;
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                int count=0;
                if(s1[ind1-1]==s2[ind2-1]) dp[ind1][ind2]=dp[ind1-1][ind2-1];
                else {
                    int replace=1+dp[ind1-1][ind2-1];
                    int remove= 1+dp[ind1-1][ind2];
                    int insert=1+dp[ind1][ind2-1];
                    
                    dp[ind1][ind2]=min({replace,remove,insert});
                }
            }
        }
        
        return dp[n][m];
        
    }
};