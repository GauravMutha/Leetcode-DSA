//Space optimisation

class Solution {
public:
    int maxProfit(vector<int>& prices){
        
        int n=prices.size();
        vector<vector<int>> dp (2,vector<int>(3,0));
        
        for(int ind=n-1;ind>=0;ind--){
            
            vector<vector<int>>tempDP(2,vector<int>(3,0));
            
            for(int canBuy=0;canBuy<=1;canBuy++){
                for(int cap=1;cap<=2;cap++){
                    
                    int profit=0;
                    
                    if(canBuy==1){
                        int buy=-prices[ind]+dp[0][cap];
                        int skipBuying=dp[1][cap];

                        profit=max(buy,skipBuying);
                    }
                    else{
                        int sell= +prices[ind]+dp[1][cap-1];
                        int skipSelling= dp[0][cap];

                        profit=max(sell,skipSelling);
                    }

                    tempDP[canBuy][cap]=profit;
                }
            }
            dp=move(tempDP);
        }
        
         return dp[1][2];
    }
};