//Tabulation

class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        
        int n=nums.size();
        vector<vector<long long>>dp(n+1,vector<long long>(2,0));
        
        for(int ind=n-1;ind>=1;ind--){
            for(int parity=0;parity<=1;parity++){
                
                long long pick = nums[ind]- (!(parity==(nums[ind]%2)))*x + dp[ind+1][nums[ind]%2];
                long long notPick = dp[ind+1][parity];

                dp[ind][parity]=max(pick,notPick);
            }
        }
        
        return (nums[0]+dp[1][nums[0]%2]);
    }
};