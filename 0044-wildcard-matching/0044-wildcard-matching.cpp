//Tabulation
class Solution {
public:
    bool isMatch(string s, string t) {
        
        int n=s.size() , m=t.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        
        //initialising dp 
        dp[0][0]=true;
        for(int ind2=1;ind2<=m;ind2++){
            dp[0][ind2]=(t.substr(0,ind2)==string(ind2,'*')); 
        }
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s[ind1-1]==t[ind2-1] || t[ind2-1]=='?')
                        dp[ind1][ind2]=dp[ind1-1][ind2-1];
                else if(t[ind2-1]=='*') 
                        dp[ind1][ind2]=(dp[ind1-1][ind2] || dp[ind1][ind2-1]);
            }
        }
        
        return dp[n][m];
    }
};