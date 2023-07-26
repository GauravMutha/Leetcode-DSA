// Exactly similar to its III version

//Tabulation
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n=prices.size();
        
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int tid=2*k-1;tid>=0;tid--){
                
                int profit=0;
        
                if(tid%2==0){
                    
                    int buy=-prices[ind]+dp[ind+1][tid+1];
                    int skipBuying= dp[ind+1][tid];

                    profit=max(buy,skipBuying);
                }
                else{
                    int sell= +prices[ind]+dp[ind+1][tid+1];
                    int skipSelling= dp[ind+1][tid];

                    profit=max(sell,skipSelling);
                }

                dp[ind][tid]=profit;
            }
        }
        
         return dp[0][0];
    }
};