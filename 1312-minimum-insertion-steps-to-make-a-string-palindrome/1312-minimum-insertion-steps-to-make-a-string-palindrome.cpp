/*We need to do just one operation
on whatever answer we get from 516
longest palindromic subsequence*/

//Memoization
class Solution {
public:
    //below two are exact functions from 516.longest palindromic subsequence
    int helper(int ind1,int ind2,string& text1,string& text2,vector<vector<int>>& dp){
        if(ind1<0 || ind2<0) return 0;
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        if(text1[ind1]==text2[ind2]) return 1+helper(ind1-1,ind2-1,text1,text2,dp);
        
        return dp[ind1][ind2]=max(helper(ind1-1,ind2,text1,text2,dp),helper(ind1,ind2-1,text1,text2,dp));
        
    }
    int longestPalindromeSubseq(string& s1) {
        string s2(s1.rbegin(),s1.rend());
        int n=s1.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return helper(n-1,n-1,s1,s2,dp);
    }
    
    int minInsertions(string s) {
        int res=longestPalindromeSubseq(s);
        
        return s.size()-res;
    }
};