//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Using tabulation
class Solution{
    
  public:
	int minDifference(int arr[], int n)  {
	    int k=accumulate(arr,arr+n,0), res=INT_MAX;
	    vector<vector<bool>>dp(n,vector<bool>(k/2+1,false));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(arr[0]<=(k/2)) dp[0][arr[0]]=true;
        
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=(k/2);target++){
                bool notPick= dp[ind-1][target];
                bool pick=false;
                if(arr[ind]<=target) pick= dp[ind-1][target-arr[ind]];

                dp[ind][target]= (pick || notPick);
            }
        }
        for(int i=0;i<dp[0].size();i++){
            if(dp[n-1][i]==false) continue;
            res=min(res,abs(k-2*i));
        }
        
        return res;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends