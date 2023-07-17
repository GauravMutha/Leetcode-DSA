//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Memeoization
class Solution {
  private:
    int mod=1000000007;
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
    
	    return dp[ind][target]=(pick+notPick)%mod;
    }
    int countPartitions(int n, int d, vector<int>& nums) {
        
        int total=accumulate(begin(nums),end(nums),0);
        if( (total-d)%2 || (total-d)<0 ) return false;
        int target=(total-d)/2;
	    
	    vector<vector<int>>dp(n,vector<int>(total+1,-1));
	
	    return helper(n-1,target,nums,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends