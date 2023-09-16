//BInary Search
class Solution {
public:
    int m=0,n=0;
    int dir[5]={0,-1,0,1,0};
    bool dfs(int i,int j, int prev, int target,vector<vector<bool>>& vis,vector<vector<int>>& grid){
        
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || abs(grid[i][j]-prev)>target) return false;
        
        vis[i][j]=true;
        if(i==m-1 && j==n-1) return true;
        
        int curr=grid[i][j];
        return ( dfs(i,j+1,curr,target,vis,grid)||
                dfs(i+1,j,curr,target,vis,grid) || 
                dfs(i-1,j,curr,target,vis,grid) || 
                dfs(i,j-1,curr,target,vis,grid) );
    }
    
    int minimumEffortPath(vector<vector<int>>& grid) {
        
        m=grid.size();
        n=grid[0].size();
        
        int low=0, high=1e6;
        
        while(low<high){
            
            int mid=low+(high-low)/2;
            vector<vector<bool>>vis(m,vector<bool>(n,false));
            if(dfs(0,0,grid[0][0],mid,vis,grid)) high=mid;
            else low=mid+1;
        }
        
        return low;
    }
};