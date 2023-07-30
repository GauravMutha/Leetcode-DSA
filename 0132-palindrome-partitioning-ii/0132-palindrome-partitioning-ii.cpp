//Tabulation

class Solution {
public:
    
    bool palinCheck(string &s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    
    int minCut(string s) {
        
        int n=s.size();
        
        vector<int>dp(n+1,0);
        dp[n]=0;
        
        for(int ind=n-1;ind>=0;ind--){
            
            int minCuts=INT_MAX;

            for(int i=ind;i<s.size();i++){
                
                if(palinCheck(s,ind,i)==false) continue;

                int cuts=1+dp[i+1];

                minCuts=min(cuts,minCuts);
                
            }

            dp[ind]=minCuts;
        }
        
        return dp[0]-1;
    }
};