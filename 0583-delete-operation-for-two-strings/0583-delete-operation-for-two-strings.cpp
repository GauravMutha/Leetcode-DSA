/*We only need to do just one operation
on whatever result we get from 1143.longest 
common subsequence,that's all*/

//Memoization
class Solution {
public:
    //below 2 functions are as it is from 1143.Longest common subsequecnce
    int helper(int ind1,int ind2,string& text1,string& text2,vector<vector<int>>& dp){
        if(ind1<0 || ind2<0) return 0;
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        if(text1[ind1]==text2[ind2]) return 1+helper(ind1-1,ind2-1,text1,text2,dp);
        
        return dp[ind1][ind2]=max(helper(ind1-1,ind2,text1,text2,dp),helper(ind1,ind2-1,text1,text2,dp));
        
    }
    int longestCommonSubsequence(string& text1, string& text2) {
        int n1=text1.size() , n2=text2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return helper(n1-1,n2-1,text1,text2,dp);
    }
    
    int minDistance(string word1, string word2) {
        int lcsLength=longestCommonSubsequence(word1,word2);
        
        int totalLength=word1.size()+word2.size();
        
        return totalLength-2*lcsLength;
    }
};