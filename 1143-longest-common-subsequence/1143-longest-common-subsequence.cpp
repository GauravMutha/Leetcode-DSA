//Tabulation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size() , n2=text2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,0));
        
        //Following two for loops handles bases cases
        for(int i=0;i<n2;i++){
            if(i==0) dp[0][i]=(text1[0]==text2[i]);
            else if(text1[0]==text2[i]) dp[0][i]=1;
            else dp[0][i]=dp[0][i-1];
        }
        for(int i=0;i<n1;i++){
            if(i==0) dp[i][0]=(text1[i]==text2[0]);
            else if(text1[i]==text2[0]) dp[i][0]=1;
            else dp[i][0]=dp[i-1][0];
        } 
        
        
        for(int ind1=1;ind1<n1;ind1++){
            for(int ind2=1;ind2<n2;ind2++){
                int count=0;
                if(text1[ind1]==text2[ind2]) count=1+dp[ind1-1][ind2-1];
                else count= max(dp[ind1-1][ind2] , dp[ind1][ind2-1]);
                
                dp[ind1][ind2]=count;
            }
        }
        
        
        
        return dp[n1-1][n2-1];
    }
};