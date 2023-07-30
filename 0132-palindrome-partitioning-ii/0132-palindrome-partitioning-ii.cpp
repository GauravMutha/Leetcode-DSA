
//Memoization

class Solution {
public:
    
    bool palinCheck(string &s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    
    int helper(int ind,string &s,vector<int>& dp){
        
        if(ind==s.size()) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int minCuts=INT_MAX;
        
        for(int i=ind;i<s.size();i++){
            
            if(palinCheck(s,ind,i)==false) continue;
            
            int cuts=1+helper(i+1,s,dp);
            
            minCuts=min(cuts,minCuts);
        }
        
        return dp[ind]=minCuts;
    }
    int minCut(string s) {
        
        int n=s.size();
        
        vector<int>dp(n,-1);
        
        return helper(0,s,dp)-1;
    }
};