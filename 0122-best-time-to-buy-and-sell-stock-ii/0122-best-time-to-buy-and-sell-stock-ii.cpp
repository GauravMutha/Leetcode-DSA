//DP
//Space optimisation
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<int>dp (2,0);
        
        //initialising dp
        dp[1]=0;
        dp[0]=prices[n-1];
        
        for(int ind=n-2;ind>=0;ind--){
            vector<int>tempDP(2,0);
            
            for(int canBuy=0;canBuy<=1;canBuy++){
                
                int profit=0;
                
                if(canBuy==1){
                    int buy=-prices[ind]+dp[0];
                    int skipBuying=dp[1];
            
                    profit=max(buy,skipBuying);
                }
                else{
                    int sell=+prices[ind]+dp[1];
                    int skipSelling=dp[0];
            
                    profit=max(sell,skipSelling);
                }
                
                tempDP[canBuy]=profit;
            }
            
            dp=move(tempDP);
        }
        
        return dp[1];
    }
};