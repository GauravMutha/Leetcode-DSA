//Using transaction id tid ,replacing cap and buy
//dp is of Nx4 , instead of Nx2x3

//Tabulation
typedef vector<vector<vector<int>>> v3d;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<int>>dp(n+1,vector<int>(5,0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int tid=3;tid>=0;tid--){
                
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