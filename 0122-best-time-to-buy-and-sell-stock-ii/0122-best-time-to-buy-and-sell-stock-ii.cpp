//DP
//Tabulation
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
        
        //initialising dp
        dp[n-1][1]=0;
        dp[n-1][0]=prices[n-1];
        
        for(int ind=n-2;ind>=0;ind--){
            for(int canBuy=0;canBuy<=1;canBuy++){
                
                int profit=0;
                
                if(canBuy==1){
                    int buy=-prices[ind]+dp[ind+1][0];
                    int skipBuying=dp[ind+1][1];
            
                    profit=max(buy,skipBuying);
                }
                else{
                    int sell=+prices[ind]+dp[ind+1][1];
                    int skipSelling=dp[ind+1][0];
            
                    profit=max(sell,skipSelling);
                }
                
                dp[ind][canBuy]=profit;
            }
        }
        
        return dp[0][1];
    }
};