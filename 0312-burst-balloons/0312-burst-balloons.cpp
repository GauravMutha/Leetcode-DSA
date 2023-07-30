//Memoization
class Solution {
public:
    int helper(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int maxCoins=INT_MIN;

        for(int ind=i;ind<=j;ind++){
            int coins=(nums[i-1]*nums[ind]*nums[j+1]+
                      helper(i,ind-1,nums,dp)+helper(ind+1,j,nums,dp));
            maxCoins=max(coins,maxCoins);
        }

        return dp[i][j]=maxCoins;
    }
    int maxCoins(vector<int>& nums) {
        
        int lastIndex=nums.size();
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        vector<vector<int>> dp(lastIndex+1,vector<int>(lastIndex+1,-1));

        return helper(1,lastIndex,nums,dp);
    }
};