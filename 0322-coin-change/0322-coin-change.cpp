//memoization
class Solution {
public:
    int helper(int ind,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(amount==0) return 0;
        if(ind==0){
            if((amount%coins[0])==0) return (amount/coins[0]);
            else return 1e9;
        }
        
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        
        int notPick=helper(ind-1,amount,coins,dp);
        int pick=INT_MAX;
        if(coins[ind]<=amount) pick=1+helper(ind,amount-coins[ind],coins,dp);
        
        return dp[ind][amount]=min(pick,notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int res= helper(n-1,amount,coins,dp);
        
        return (res==1e9) ? -1 : res;
    }
};