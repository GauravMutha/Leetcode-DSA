/*We need to do just one operation
on whatever answer we get from 516
longest palindromic subsequence*/

//Space optimisation
class Solution {
public:
    //below function is as it is in from 516.longest palindromic subsequence
    
    int longestPalindromeSubseq(string& s1) {
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
    
    int minInsertions(string s) {
        int res=longestPalindromeSubseq(s);
        
        return s.size()-res;
    }
};