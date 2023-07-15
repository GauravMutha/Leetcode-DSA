//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Using memoization
class Solution{
    
  public:
  int helper(int ind,int sum1,int sum2,vector<vector<int>>& dp,int n,int arr[]){
      if(ind==n) return abs(sum1-sum2);
      
      if(dp[ind][abs(sum1-sum2)]!=-1) return dp[ind][abs(sum1-sum2)];
      
      int pick=helper(ind+1,sum1+arr[ind],sum2,dp,n,arr);
      int notPick=helper(ind+1,sum1,sum2+arr[ind],dp,n,arr);
      
      return dp[ind][abs(sum1-sum2)]=min(pick,notPick);
  }
	int minDifference(int arr[], int n)  {
	    int total=accumulate(arr,arr+n,0);
	    vector<vector<int>>dp(n,vector<int>(total+1,-1));
	    
	    return helper(0,0,0,dp,n,arr);
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