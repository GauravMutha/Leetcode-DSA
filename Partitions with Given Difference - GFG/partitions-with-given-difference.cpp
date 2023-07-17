//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    int mod=1000000007;
  public:
    int countPartitions(int n, int d, vector<int>& nums) {
        
        int total=accumulate(begin(nums),end(nums),0);
        if( (total-d)%2 || (total-d)<0 ) return 0;
        int target=(total-d)/2;
	    
	    vector<vector<int>>dp(n,vector<int>(target+1,0));

	    if(nums[0]==0) dp[0][0]=2;
	    else dp[0][0]=1;
	    if(nums[0]!=0 && nums[0]<=target) dp[0][nums[0]]=1;
	
	    for(int ind=1;ind<n;ind++){
		    for(int k=0;k<=target;k++){
			    int notPick=dp[ind-1][k];
			    int pick=0;
			    if(nums[ind]<=k) pick=dp[ind-1][k-nums[ind]];

			    dp[ind][k]=(pick+notPick)%mod;
		    }
	    }
	    return dp[n-1][target];
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