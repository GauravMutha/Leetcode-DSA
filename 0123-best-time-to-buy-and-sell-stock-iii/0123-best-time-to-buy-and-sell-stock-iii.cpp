//Using transaction id tid ,replacing cap and buy

//Space Optimisation
typedef vector<vector<vector<int>>> v3d;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<int> dp(5,0);
        
        for(int ind=n-1;ind>=0;ind--){
            
            vector<int>tempDP(5,0);
            
            for(int tid=3;tid>=0;tid--){
                
                int profit=0;
        
                if(tid%2==0){
                    
                    int buy=-prices[ind]+dp[tid+1];
                    int skipBuying= dp[tid];

                    profit=max(buy,skipBuying);
                }
                else{
                    int sell= +prices[ind]+dp[tid+1];
                    int skipSelling= dp[tid];

                    profit=max(sell,skipSelling);
                }

                tempDP[tid]=profit;
            }
            dp=move(tempDP);
        }
        
         return dp[0];
    }
};