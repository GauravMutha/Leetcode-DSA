//Space optimisation
//As per first to last memo
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>dp (n+1,0);
        
        for(int ind=n-1;ind>=0;ind--){
            
            vector<int>tempDP(n+1,0);
            
            for(int preInd=ind-1;preInd>=-1;preInd--){
                
                int pick=0;
                if(preInd==-1 || nums[ind]>nums[preInd]) pick=1+dp[ind+1];
                int notPick=dp[preInd+1];
                
                tempDP[preInd+1]=max(pick,notPick);
            }
            
            dp=move(tempDP);
        }
        
        return dp[0];
    }
};