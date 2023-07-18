/*Totally converting this question into DP-18 "partitions 
with given differences" (striver dp sheet)*/
class Solution {
public:
    int helper(int ind, int target, vector<int> &nums,vector<vector<int>>& dp){

        if(ind==0){
            if(target==0 && nums[0]==0) return 2;
            if(target==0 || nums[0]==target) return 1;
            
            return 0;
        }

        if(dp[ind][target]!=-1) return dp[ind][target];

        int notPick=helper(ind-1,target,nums,dp);
        int pick=0;
        if(nums[ind]<=target) pick=helper(ind-1,target-nums[ind],nums,dp);

        return dp[ind][target]=(pick+notPick);
    }
    int findTargetSumWays(vector<int>& nums, int d) {
        int total=accumulate(begin(nums),end(nums),0) , n=nums.size();
        if( (total-d)%2 || (total-d)<0 ) return false;
        int target=(total-d)/2;
	    
	    vector<vector<int>>dp(n,vector<int>(target+1,-1));
	
	    return helper(n-1,target,nums,dp);
    }
};