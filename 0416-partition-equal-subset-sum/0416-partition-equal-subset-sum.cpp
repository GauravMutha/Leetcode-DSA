//tabulation space optimisation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total%2) return false; //two equal integers cannot add upto an odd number
        int k=total/2;
        
        vector<bool>dp(k+1,false);
        dp[0]=true;
        if(nums[0]<=k) dp[nums[0]]=true;
        for(int ind=1;ind<n;ind++){
            vector<bool>tempDP(k+1,false);
            tempDP[0]=true;
            for(int target=1;target<=k;target++){
                bool notPick= dp[target];
                bool pick=false;
                if(nums[ind]<=target) pick= dp[target-nums[ind]];

                tempDP[target]= (pick || notPick);
            }
            dp=move(tempDP);
        }
        return dp[k];
    }
};