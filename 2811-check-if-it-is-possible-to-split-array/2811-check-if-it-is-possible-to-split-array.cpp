//memoization
class Solution {
private:
    vector<int>pre;    
public:
    int helper(int i,int j,int m,vector<int>& nums,vector<vector<int>>& dp){
        
        if(i==j) return dp[i][j]=1; 
        if(i>j || (pre[j]-pre[i]+nums[i])<m) return dp[i][j]=0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        for(int k=i;k<j;k++){
            bool possible=(helper(i,k,m,nums,dp) && helper(k+1,j,m,nums,dp));
            
            if(possible) return dp[i][j]=1;
        }
        
        return dp[i][j]=0;
    }
    bool canSplitArray(vector<int>& nums, int m) {
        
        int n=nums.size();
        if(n<=2) return true;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        pre.resize(n);
        pre[0]=nums[0];
        
        for(int i=1;i<n;i++)
            pre[i]=nums[i]+pre[i-1];
        
        return helper(0,n-1,m,nums,dp);
    }
};