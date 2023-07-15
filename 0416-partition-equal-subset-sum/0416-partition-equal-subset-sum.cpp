//tabulation
class Solution {
public:
    bool helper(int ind, int target,vector<vector<int>>& dp,vector<int>& nums){
        if(target==0) return true;
        if(ind==0) return (nums[0]==target);
    
        if(dp[ind][target]!=-1) return dp[ind][target];
    
        bool notPick= helper(ind-1,target,dp,nums);
        bool pick=false;
        if(nums[ind]<=target) pick= helper(ind-1,target-nums[ind],dp,nums);
    
        return dp[ind][target]= (pick || notPick);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total%2) return false; //two equal integers cannot add upto an odd number
        int k=total/2;
        
        vector<vector<bool>>dp(n,vector<bool>(k+1,false));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(nums[0]<=k) dp[0][nums[0]]=true;
        
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=k;target++){
                bool notPick= dp[ind-1][target];
                bool pick=false;
                if(nums[ind]<=target) pick= dp[ind-1][target-nums[ind]];

                dp[ind][target]= (pick || notPick);
            }
        }
        return dp[n-1][k];
    }
};