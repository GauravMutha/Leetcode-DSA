class Solution {
private:
    int m=0,n=0;
public:
    void dfs(int i,int j,vector<vector<bool>>& vis,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0' || vis[i][j]==true)
            return;
        
        vis[i][j]=true;
        dfs(i,j+1,vis,grid);
        dfs(i,j-1,vis,grid);
        dfs(i+1,j,vis,grid);
        dfs(i-1,j,vis,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        m=grid.size() , n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='0' || vis[i][j]==true) continue;
                dfs(i,j,vis,grid);
                count++;
            }
        }
        
        return count;
    }
};