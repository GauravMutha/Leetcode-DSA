//Memoization
class Solution {
public:
    int helper(int ind1,int ind2,string s1,string s2,vector<vector<int>>& dp){
        
        if(ind2<0) return ind1+1;
        if(ind1<0) return ind2+1;
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        if(s1[ind1]==s2[ind2]) return dp[ind1][ind2]= helper(ind1-1,ind2-1,s1,s2,dp);
        
        
        int replace=1+helper(ind1-1,ind2-1,s1,s2,dp);
        int remove= 1+helper(ind1-1,ind2,s1,s2,dp);
        int insert=1+helper(ind1,ind2-1,s1,s2,dp);
        
        return dp[ind1][ind2]=min({replace,remove,insert});
        
    }
    int minDistance(string s1, string s2) {
        
        int n=s1.size() , m=s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return helper(n-1,m-1,s1,s2,dp);
        
    }
};