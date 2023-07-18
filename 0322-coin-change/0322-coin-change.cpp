//Space optimisation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        vector<int>dp(amount+1,0);
        
        for(int a=0;a<=amount;a++){
            if((a%coins[0])==0) 
                dp[a]=(a/coins[0]);
            else dp[a]=1e9;
        }
        
        for(int ind=1;ind<n;ind++){
            vector<int>tempDP(amount+1,0);
            for(int a=0;a<=amount;a++){
                
                int notPick=0+dp[a];
                
                int pick=1e9;
                if(coins[ind]<=a) pick=1+tempDP[a-coins[ind]];
        
                tempDP[a]=min(pick,notPick);
            }
            dp=move(tempDP);
        }
        
        if(dp[amount]>=1e9) return -1;
        
        return dp[amount];
    }
};