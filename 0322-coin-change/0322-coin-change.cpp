//Tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        
        for(int a=0;a<=amount;a++){
            if((a%coins[0])==0) 
                dp[0][a]=(a/coins[0]);
            else dp[0][a]=1e9;
        }
        
        for(int ind=1;ind<n;ind++){
            for(int a=0;a<=amount;a++){
                
                int notPick=0+dp[ind-1][a];
                
                int pick=INT_MAX;
                if(coins[ind]<=a) pick=1+dp[ind][a-coins[ind]];
        
                dp[ind][a]=min(pick,notPick);
            }
        }
        
        if(dp[n-1][amount]>=1e9) return -1;
        
        return dp[n-1][amount];
    }
};