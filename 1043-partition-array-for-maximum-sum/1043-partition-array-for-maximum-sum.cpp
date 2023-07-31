//Tabulation

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>dp(n+1,0);
        
        for(int ind=n-1;ind>=0;ind--){
            
            int maxSum=INT_MIN , maxVal=INT_MIN;
        
            for(int i=ind;i<(ind+k) && i<nums.size();i++){

                maxVal=max(nums[i],maxVal);
                int sum=(i-ind+1)*maxVal+dp[i+1];
                maxSum=max(sum,maxSum);
            }

            dp[ind]=maxSum;
        }
        return dp[0];
    }
};