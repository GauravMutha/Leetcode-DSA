class Solution {
private:
    int m=0,n=0;
public:
    void dfs(int i,int j,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0')
            return;
        
        grid[i][j]='0';
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        m=grid.size() , n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='0') continue;
                dfs(i,j,grid);
                count++;
            }
        }
        
        return count;
    }
};