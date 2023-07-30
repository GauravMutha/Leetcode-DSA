//Tabulation
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        int lastIndex=nums.size();
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        vector<vector<int>> dp(lastIndex+2,vector<int>(lastIndex+2,0));

        for(int i=lastIndex;i>=1;i--){
            for(int j=i;j<=lastIndex;j++){
                
                int maxCoins=INT_MIN;

                for(int ind=i;ind<=j;ind++){
                    int coins=(nums[i-1]*nums[ind]*nums[j+1]+ 
                              dp[i][ind-1]+dp[ind+1][j]);
                    maxCoins=max(coins,maxCoins);
                }

                dp[i][j]=maxCoins;
            }
        }
        
        return dp[1][lastIndex];
    }
};