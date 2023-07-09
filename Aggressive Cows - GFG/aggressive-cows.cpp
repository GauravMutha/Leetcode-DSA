//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool check(int dist, vector<int>& stalls,int cows){
        int lastPos=stalls[0] , count=1;
        for(int i=1;i<stalls.size() && (count<cows);i++){
            if((stalls[i]-lastPos)<dist) continue;
            count++;
            lastPos=stalls[i];
        }
        return (count==cows);
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        
        int low=1 , high=stalls.back()-stalls[0] , res=0;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(check(mid,stalls,k)){
                res=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        
        return high;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends