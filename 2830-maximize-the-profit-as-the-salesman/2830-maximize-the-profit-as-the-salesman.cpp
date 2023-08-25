//Memoization
//Using STL for Upper bound directly
class Solution {
public:
    int helper(int ind,vector<vector<int>>& offers,vector<int>& dp){
        if(ind>=offers.size()) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        
        
        auto nextInd = std::upper_bound(offers.begin() + ind + 1, offers.end(), offers[ind][1],
                           [](int val, const std::vector<int>& a) {
                               return val < a[0];
                           }) - offers.begin();

        
        int notPick=helper(ind+1,offers,dp);
        int pick=offers[ind][2]+helper(nextInd,offers,dp);
        
        return dp[ind]=max(notPick,pick);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m=offers.size();
        sort(offers.begin(),offers.end());
        vector<int> dp(m,-1);
        return helper(0,offers,dp);
    }
};