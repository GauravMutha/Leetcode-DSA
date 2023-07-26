//Memoization
typedef vector<vector<vector<int>>> v3d;
class Solution {
public:
    int helper(int ind,int canBuy,int cap,vector<int>& prices,v3d &dp){
        if(ind==prices.size() || cap==0) return 0;
        
        if(dp[ind][canBuy][cap]!=-1) return dp[ind][canBuy][cap];
        
        int profit=0;
        if(canBuy==1){
            int buy=-prices[ind]+helper(ind+1,false,cap,prices,dp);
            int skipBuying= helper(ind+1,true,cap,prices,dp);
            
            profit=max(buy,skipBuying);
        }
        else{
            int sell= +prices[ind]+helper(ind+1,true,cap-1,prices,dp);
            int skipSelling= helper(ind+1,false,cap,prices,dp);
            
            profit=max(sell,skipSelling);
        }
        
        return dp[ind][canBuy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // 3d vector v3d
        v3d dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
         
        return helper(0,1,2,prices,dp);
    }
};