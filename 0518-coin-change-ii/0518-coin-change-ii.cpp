//Memoization
//Almost ditto similar to coin change-I (DP-22)
class Solution {
public:
    int helper(int ind,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(amount==0) return 1;
        if(ind==0){
            if((amount%coins[0])==0) return 1;
            else return 0;
        }
        
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        
        int notPick=helper(ind-1,amount,coins,dp);
        int pick=0;
        if(coins[ind]<=amount) pick=helper(ind,amount-coins[ind],coins,dp);
        
        return dp[ind][amount]=(pick+notPick);
    }
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(n-1,amount,coins,dp);
    }
};