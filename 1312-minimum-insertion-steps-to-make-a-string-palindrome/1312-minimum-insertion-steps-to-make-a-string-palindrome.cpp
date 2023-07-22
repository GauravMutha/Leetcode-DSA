/*We need to do just one operation
on whatever answer we get from 516
longest palindromic subsequence*/

//Tabulation
class Solution {
public:
    //below function is as it is in from 516.longest palindromic subsequence
    
    int longestPalindromeSubseq(string& s1) {
        string s2(s1.rbegin(),s1.rend());
        int n=s1.size();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                int count=0;
                if(s1[ind1-1]==s2[ind2-1]) count=1+dp[ind1-1][ind2-1];
                else count= max(dp[ind1-1][ind2] , dp[ind1][ind2-1]);
                
                dp[ind1][ind2]=count;
            }
        }
        
        return dp[n][n];
    }
    
    int minInsertions(string s) {
        int res=longestPalindromeSubseq(s);
        
        return s.size()-res;
    }
};