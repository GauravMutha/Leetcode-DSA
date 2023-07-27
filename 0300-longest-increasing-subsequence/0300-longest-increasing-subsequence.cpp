//Tabulation
//As per first to last memo
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int preInd=ind-1;preInd>=-1;preInd--){
                
                int pick=0;
                if(preInd==-1 || nums[ind]>nums[preInd]) pick=1+dp[ind+1][ind+1];
                int notPick=dp[ind+1][preInd+1];
                
                dp[ind][preInd+1]=max(pick,notPick);
            }
        }
        
        return dp[0][0];
    }
};