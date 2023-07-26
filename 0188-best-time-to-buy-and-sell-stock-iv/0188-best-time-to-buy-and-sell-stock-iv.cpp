// Exactly similar to its III version
//We only change 4 to k

//Memoization
class Solution {
public:
    int helper(int ind,int tid,vector<int>& prices,vector<vector<int>>&dp)   {
        
        if(ind==prices.size() || tid>=dp[0].size()) return 0;
        
        if(dp[ind][tid]!=-1) return dp[ind][tid];
        
        int profit=0;
        
        if(tid%2==0){
            int buy=-prices[ind]+helper(ind+1,tid+1,prices,dp);
            int skipBuying= helper(ind+1,tid,prices,dp);
            
            profit=max(buy,skipBuying);
        }
        else{
            int sell= +prices[ind]+helper(ind+1,tid+1,prices,dp);
            int skipSelling= helper(ind+1,tid,prices,dp);
            
            profit=max(sell,skipSelling);
        }
        
        return dp[ind][tid]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2*k,-1));
         
        return helper(0,0,prices,dp);
    }
};