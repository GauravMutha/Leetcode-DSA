//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    vector<string>res;
    void helper(int i,int j,string ds,vector<vector<bool>>& vis,vector<vector<int>>& grid,int n){
        
        if(i==(n-1) && j==(n-1)){
            res.push_back(ds);
            return;
        }
        
        
        
        if( (i-1)>=0 && grid[i-1][j] && !vis[i-1][j]){
            vis[i][j]=true;
            helper(i-1,j,ds+'U',vis,grid,n);
            vis[i][j]=false;
        }
        
        if( (j-1)>=0 && grid[i][j-1] && !vis[i][j-1]){
            vis[i][j]=true;
            helper(i,j-1,ds+'L',vis,grid,n);
            vis[i][j]=false;
        }
        
        if( (i+1)<n && grid[i+1][j] && !vis[i+1][j]){
            vis[i][j]=true;
            helper(i+1,j,ds+'D',vis,grid,n);
            vis[i][j]=false;
        }
        
        if( (j+1)<n && grid[i][j+1] && !vis[i][j+1]){
            vis[i][j]=true;
            helper(i,j+1,ds+'R',vis,grid,n);
            vis[i][j]=false;
        }   
    }
    public:
    vector<string> findPath(vector<vector<int>> &grid, int n) {
        if(grid[0][0]==0 || grid[n-1][n-1]==0) return res;
        string ds="";
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        helper(0,0,ds,vis,grid,n);
        
        return res;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends