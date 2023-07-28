//Tabulation 2.0
//Using hash

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size(),res=1;
        vector<int>dp (n,1);
        
        for(int ind=0;ind<n;ind++){
            for(int pre=0;pre<ind;pre++){
                if(nums[pre]<nums[ind])
                    dp[ind]=max(1+dp[pre],dp[ind]);
            }
            res=max(res,dp[ind]);
        }
        
        return res;
    }
};