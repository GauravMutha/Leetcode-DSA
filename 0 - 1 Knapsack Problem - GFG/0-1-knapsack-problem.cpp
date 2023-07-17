//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Memoization
class Solution
{
    public:
    int res=-1;
    int helper(int ind,int cap,int wt[],int val[],vector<vector<int>>& dp){
        if(ind==0){
            if(wt[0]<=cap){
                return val[0];
            }
            else return 0;
        }
        
        if(dp[ind][cap]!=-1) return dp[ind][cap];

	    int notPick=0+helper(ind-1,cap,wt,val,dp);
	    int pick=INT_MIN;
	    if(wt[ind]<=cap) pick=val[ind]+helper(ind-1,cap-wt[ind],wt,val,dp);

	    return dp[ind][cap]=max(pick,notPick);
    }
    int knapSack(int cap, int wt[], int val[], int n) 
    {
	    vector<vector<int>>dp(n,vector<int>(cap+1,0));
	    for(int w=wt[0];w<=cap;w++) dp[0][w]=val[0];
	    
	    for(int ind=1;ind<n;ind++){
	        for(int w=0;w<=cap;w++){
	            int notPick=dp[ind-1][w];
	            int pick=INT_MIN;
	            if(wt[ind]<=w)pick=val[ind]+dp[ind-1][w-wt[ind]];
	            
	            dp[ind][w]=max(pick,notPick);
	        }
	    }
	    
	    return dp[n-1][cap];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends