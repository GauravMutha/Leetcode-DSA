//Tabulation
typedef vector<vector<vector<int>>> v3d;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // 3d vector v3d , we did n+1 here , index shifting
        v3d dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int canBuy=0;canBuy<=1;canBuy++){
                for(int cap=1;cap<=2;cap++){
                    
                    int profit=0;
                    
                    if(canBuy==1){
                        int buy=-prices[ind]+dp[ind+1][0][cap];
                        int skipBuying=dp[ind+1][1][cap];

                        profit=max(buy,skipBuying);
                    }
                    else{
                        int sell= +prices[ind]+dp[ind+1][1][cap-1];
                        int skipSelling= dp[ind+1][0][cap];

                        profit=max(sell,skipSelling);
                    }

                    dp[ind][canBuy][cap]=profit;
                    
                }
            }
        }
        
         return dp[0][1][2];
    }
};