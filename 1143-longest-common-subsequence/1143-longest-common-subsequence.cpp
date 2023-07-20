//Tabulation with index shifting
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size() , n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        
        
        
        for(int ind1=1;ind1<=n1;ind1++){
            for(int ind2=1;ind2<=n2;ind2++){
                int count=0;
                if(text1[ind1-1]==text2[ind2-1]) count=1+dp[ind1-1][ind2-1];
                else count= max(dp[ind1-1][ind2] , dp[ind1][ind2-1]);
                
                dp[ind1][ind2]=count;
            }
        }
        
        
        
        return dp[n1][n2];
    }
};