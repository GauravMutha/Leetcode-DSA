//Memoization
class Solution {
public:
    bool helper(int ind1,int ind2,string &s,string &t,vector<vector<int>>& dp){
        
        if(ind2<0) return ind1<0;
        if(ind1<0 && ind2>=0) return (t.substr(0,ind2+1)==string(ind2+1,'*'));
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        if(s[ind1]==t[ind2] || t[ind2]=='?')
            return dp[ind1][ind2]=helper(ind1-1,ind2-1,s,t,dp);
        else if(t[ind2]=='*') 
            return dp[ind1][ind2]=(helper(ind1-1,ind2,s,t,dp) || helper(ind1,ind2-1,s,t,dp));
        
        return dp[ind1][ind2]=false; //characters are not matching
    }
    bool isMatch(string s, string t) {
        
        int n=s.size() , m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return helper(n-1,m-1,s,t,dp);
    }
};