//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int count(int k ,vector<vector<int>> &matrix){
        int r=matrix.size() , c=matrix[0].size();
        int res=0;
        for(int i=0;i<r;i++){
            
            int low=0 , high=c-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                
                if(matrix[i][mid]<=k) low=mid+1;
                else high=mid-1;
            }
            res+=low;
        }
        return res;
    }
    int median(vector<vector<int>> &matrix, int r,int c){
        int minVal=INT_MAX , maxVal=INT_MIN;
        for(int i=0;i<r;i++){
            minVal=min(matrix[i][0],minVal);
            maxVal=max(matrix[i][c-1],maxVal);
        }
        
        int low=minVal, high=maxVal;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(count(mid,matrix) > (r*c)/2)
                high=mid-1;
            else low=mid+1;
        }
        
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends