//Space Optimisation
class Solution {
public:
    bool isMatch(string s, string t) {
        
        int n=s.size() , m=t.size();
        vector<bool>dp(m+1,false);
        
        //initialising dp
        dp[0]=true;
        for(int ind2=1;ind2<=m;ind2++){
            dp[ind2]=(t.substr(0,ind2)==string(ind2,'*')); 
        }
        
        for(int ind1=1;ind1<=n;ind1++){
            
            vector<bool>tempDP(m+1,false);
            
            for(int ind2=1;ind2<=m;ind2++){
                if(s[ind1-1]==t[ind2-1] || t[ind2-1]=='?')
                        tempDP[ind2]=dp[ind2-1];
                else if(t[ind2-1]=='*') 
                        tempDP[ind2]=(dp[ind2] || tempDP[ind2-1]);
            }
            dp=move(tempDP);
        }
        
        return dp[m];
    }
};