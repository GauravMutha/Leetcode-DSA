//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int missingNumber(vector<int>& arr, int n) {
        vector<bool>hash(n+1,false);
        
        for(int i=0;i<n;i++){
            if(arr[i]>=hash.size()) continue;
            hash[arr[i]]=true;
        }
        
        for(int i=1;i<hash.size();i++){
            if(hash[i]==false) return i;
        }
        
        return n;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends