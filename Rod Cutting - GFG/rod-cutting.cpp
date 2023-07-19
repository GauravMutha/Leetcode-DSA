//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

//Similar to unbounded knapsack
//Treat it as collecting the pieces to make n inches long rod and trying to get the maximum price

//Space optimisation
class Solution{
  public:
    int cutRod(int price[], int length) {
        vector<int>dp(length+1,0);
        for(int l=1;l<=length;l++) dp[l]=l*price[0];
        
        for(int ind=1;ind<length;ind++){
            vector<int> tempDP(length+1,0);
            for(int l=1;l<=length;l++){
                int notPick=0+dp[l];
                int pick=INT_MIN , pieceLength=ind+1;
                
                if(pieceLength<=l) pick= price[ind]+tempDP[l-pieceLength];
                
                tempDP[l]=max(pick,notPick);
            }
            dp=move(tempDP);
        }
        
        return dp[length];
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