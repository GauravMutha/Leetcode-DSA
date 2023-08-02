//Memoization

class Solution {
private:
    int mod = 1e9+7;
public:
    int helper(int ind,int target,int x,vector<vector<int>>& dp){
        if(ind>=301) return (target==0);
        if(target==0) return 1;
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        if(target<(pow(ind,x))) return 0;
        
        int pick=helper(ind+1,target-pow(ind,x),x,dp);
        int notPick=helper(ind+1,target,x,dp);
        
        return dp[ind][target]=(pick+notPick)%mod;
    }
    int numberOfWays(int n, int x) {
        
        vector<vector<int>>dp (301,vector<int>(301,-1));
        return helper(1,n,x,dp);
        
    }
};