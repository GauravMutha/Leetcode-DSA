//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Space optimisation
class Solution
{
    public:
    int knapSack(int cap, int wt[], int val[], int n) 
    {
	    vector<int>dp(cap+1,0);
	    for(int w=wt[0];w<=cap;w++) dp[w]=val[0];
	    
	    for(int ind=1;ind<n;ind++){
	        vector<int>tempDP(cap+1,0);
	        for(int w=0;w<=cap;w++){
	            int notPick=dp[w];
	            int pick=INT_MIN;
	            if(wt[ind]<=w) pick=val[ind]+dp[w-wt[ind]];
	            
	            tempDP[w]=max(pick,notPick);
	        }
	        dp=move(tempDP);
	    }
	    
	    return dp[cap];
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