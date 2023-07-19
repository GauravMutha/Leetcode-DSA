//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
//Tabulation
class Solution
{
    public:
    int knapSack(int n,int cap, int val[], int wt[]) 
    {
	    vector<vector<int>>dp(n,vector<int>(cap+1,0));
	    for(int w=wt[0];w<=cap;w++) dp[0][w]=(w/wt[0])*val[0];
	    
	    for(int ind=1;ind<n;ind++){
	        for(int w=0;w<=cap;w++){
	            int notPick=dp[ind-1][w];
	            int pick=INT_MIN;
	            if(wt[ind]<=w)pick=val[ind]+dp[ind][w-wt[ind]];
	            
	            dp[ind][w]=max(pick,notPick);
	        }
	    }
	    
	    return dp[n-1][cap];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends