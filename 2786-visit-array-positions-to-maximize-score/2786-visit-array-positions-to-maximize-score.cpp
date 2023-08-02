//Space optimisation

class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        
        int n=nums.size();
        vector<long long>dp(2,0);
        
        for(int ind=n-1;ind>=1;ind--){
            
            vector<long long>tempDP(2,0);
            
            for(int parity=0;parity<=1;parity++){
                
                long long pick = nums[ind]- (!(parity==(nums[ind]%2)))*x + dp[nums[ind]%2];
                long long notPick = dp[parity];

                tempDP[parity]=max(pick,notPick);
            }
            
            dp=move(tempDP);
        }
        
        return (nums[0]+dp[nums[0]%2]);
    }
};