//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   unordered_map<int,int>m;
        m[0]=-1;
        int prefixSum=0,maxLen=0;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            if(m.find(prefixSum)==m.end()) m[prefixSum]=i;
            else {
                int len=i-m[prefixSum];
                maxLen=max(len,maxLen);
            }
        }
        
        return maxLen;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends