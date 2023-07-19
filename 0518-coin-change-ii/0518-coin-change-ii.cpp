//Tabulation
//Almost ditto similar to coin change-I (DP-22)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        
        for(int a=0;a<=amount;a++){
            if((a%coins[0])==0) 
                dp[0][a]=1;
            else dp[0][a]=0;
        }
        
        for(int ind=1;ind<n;ind++){
            for(int a=0;a<=amount;a++){
                
                int notPick=0+dp[ind-1][a];
                
                int pick=0;
                if(coins[ind]<=a) pick=dp[ind][a-coins[ind]];
        
                dp[ind][a]=(pick+notPick);
            }
        }
        
        
        return dp[n-1][amount];
    }
};