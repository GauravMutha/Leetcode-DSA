//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

//Similar to unbounded knapsack
//Treat it as collecting the pieces to make n inches long rod and trying to get the maximum price

//Memoization
class Solution{
  public:
    int helper(int ind,int length,int price[],vector<vector<int>>& dp){
        
        if(ind==0){
            int pieceLength=ind+1; //1 inch length, that is.
            if(pieceLength<=length) return length*price[0];
            return 0;
        }
        
        if(dp[ind][length]!=-1) return dp[ind][length];
        
        int notPick=0+helper(ind-1,length,price,dp);
        int pick = INT_MIN , pieceLength=ind+1;
        if(pieceLength<=length) pick=price[ind]+helper(ind,length-(pieceLength),price,dp);
        
        return dp[ind][length]=max(pick,notPick);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
        return helper(n-1,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends