//Memoization slightly modified and more concise

class Solution {
private:
    int mod = 1e9+7;
public:
    int helper(int ind,int target,int x,vector<vector<int>>& dp){
        
        if(target<0) return 0;
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        int val=pow(ind,x);
        if(target<val) return 0;
        if(target==val) return 1;
        
        int pick=helper(ind+1,target-pow(ind,x),x,dp);
        int notPick=helper(ind+1,target,x,dp);
        
        return dp[ind][target]=(pick+notPick)%mod;
    }
    int numberOfWays(int n, int x) {
        
        vector<vector<int>>dp (n+1,vector<int>(n+1,-1));
        return helper(1,n,x,dp);
        
    }
};