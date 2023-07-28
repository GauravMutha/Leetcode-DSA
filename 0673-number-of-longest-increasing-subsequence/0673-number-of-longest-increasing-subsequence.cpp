//Tabulation 2.0

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),maxLen=1,res=0;
        
        vector<int>dp (n,1) , count(n,1);
        
        for(int ind=0;ind<n;ind++){
            for(int pre=0;pre<ind;pre++){
                if(nums[pre]<nums[ind] && (dp[pre]+1)>dp[ind]){
                    dp[ind]=dp[pre]+1;
                    count[ind]=count[pre];
                }
                else if(nums[pre]<nums[ind] && (dp[pre]+1)==dp[ind]){
                    dp[ind]=dp[pre]+1;
                    count[ind]+=count[pre];
                }
            }
            maxLen=max(maxLen,dp[ind]);
        }
        for(int i=0;i<n;i++) if(dp[i]==maxLen)  res+=count[i];
        return res;
    }
};