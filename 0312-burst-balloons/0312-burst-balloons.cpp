class Solution {
public:
    int helper(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxCoins=INT_MIN;
        for(int k=i;k<=j;k++){
            
            int val=nums[i-1]*nums[k]*nums[j+1];
            int coins=val+helper(i,k-1,nums,dp)+helper(k+1,j,nums,dp);
            
            maxCoins=max(maxCoins,coins);
        }
        
        return dp[i][j]= maxCoins;
    }
    int maxCoins(vector<int>& nums) {
        int lastInd=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        vector<vector<int>>dp(lastInd+2,vector<int>(lastInd+2,0));
        
        for(int i=lastInd;i>=1;i--){
            for(int j=i;j<=lastInd;j++){
                
                int maxCoins=INT_MIN;
                for(int k=i;k<=j;k++){

                    int val=nums[i-1]*nums[k]*nums[j+1];
                    int coins=val+dp[i][k-1]+dp[k+1][j];

                    maxCoins=max(maxCoins,coins);
                }

                dp[i][j]= maxCoins;
            }
        }
        
        return dp[1][lastInd];
    }
};