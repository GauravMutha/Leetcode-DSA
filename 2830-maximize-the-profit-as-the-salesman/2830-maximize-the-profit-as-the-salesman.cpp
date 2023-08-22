//Memoization
//Implementing Upper bound Differently
class Solution {
public:
    int helper(int ind,vector<vector<int>>& offers,vector<int>& dp){
        if(ind>=offers.size()) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int nextInd=offers.size() , low=ind+1,high=offers.size()-1;
        
        
        while (low <= high) {
            int mid = (low+high)/2;
            if (offers[mid][0] <= offers[ind][1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        nextInd=low;
        
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