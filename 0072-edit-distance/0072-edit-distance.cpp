//Space optimisation
class Solution {
public:
    int minDistance(string s1, string s2) {
        
        int n=s1.size() , m=s2.size();
        vector<int>dp(m+1,0);
        
        //initialising dp
        for(int ind2=0;ind2<=m;ind2++) dp[ind2]=ind2;
        
        for(int ind1=1;ind1<=n;ind1++){
            vector<int>tempDP(m+1,0);
            tempDP[0]=ind1;
            for(int ind2=1;ind2<=m;ind2++){
                if(s1[ind1-1]==s2[ind2-1]) tempDP[ind2]=dp[ind2-1];
                else {
                    int replace=1+dp[ind2-1];
                    int remove= 1+dp[ind2];
                    int insert=1+tempDP[ind2-1];
                    
                    tempDP[ind2]=min({replace,remove,insert});
                }
            }
            dp=move(tempDP);
        }
        
        return dp[m];
        
    }
};