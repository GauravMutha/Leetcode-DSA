//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        //storing all the persons in stack so total n persons from 0 to n-1
        stack<int>st;
        for(int i=0;i<n;i++) st.push(i);
        
        while(st.size()>1){
            int x=st.top(); st.pop();
            int y=st.top(); st.pop();
            
            if(M[x][y]==1) st.push(y); //x cannot be celebrity
            else st.push(x); //y cannot be celebrity
        }
        
        int res=st.top();
        for(int i=0;i<n;i++){
            if(res!=i && (M[res][i]!=0 || M[i][res]!=1)) return -1;
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends