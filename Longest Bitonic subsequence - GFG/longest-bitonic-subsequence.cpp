//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Simply using Tabulation 2.0
class Solution{
	
	public:
    void LIS(vector<int>& nums,vector<int>& dp) {
        
        int n=nums.size();
        
        for(int ind=0;ind<n;ind++){
            for(int pre=0;pre<ind;pre++){
                if(nums[pre]<nums[ind])
                    dp[ind]=max(1+dp[pre],dp[ind]);
            }
        }
        
        return;
    }
    
	int LongestBitonicSequence(vector<int>nums1)
	{
	    int n=nums1.size() , res=1;
	    vector<int>nums2(nums1.rbegin(),nums1.rend());
	    
	    vector<int> dp1(n,1);
	    vector<int> dp2(n,1); //lis dp for reverse nums

	    
	    LIS(nums1,dp1);
	    LIS(nums2,dp2);
	    
	 
	    for(int i=0;i<n;i++){
	        int val=dp1[i]+dp2[n-i-1]-1;
	        res=max(res,val);
	    }
	    
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends