/*We make it exactly same as 1143 LCS.
We take reverse of given string as 
s2,and then apply lcs on s1 and s2.
*/

//Space optimisation
class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        
        string s2(s1.rbegin(),s1.rend());
        int n=s1.size();
        
        vector<int>dp (n+1,0);
        
        
        
        for(int ind1=1;ind1<=n;ind1++){
            vector<int>tempDP(n+1,0);
            
            for(int ind2=1;ind2<=n;ind2++){
                int count=0;
                if(s1[ind1-1]==s2[ind2-1]) count=1+dp[ind2-1];
                else count= max(dp[ind2] , tempDP[ind2-1]);
                
                tempDP[ind2]=count;
            }
            dp=move(tempDP);
        }
        
        
        
        return dp[n];
    }
};