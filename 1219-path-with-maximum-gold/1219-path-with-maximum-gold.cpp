//Simple backtracking
class Solution {
public:
    int travel(int i , int j ,int r, int c, vector<vector<bool>>& vis,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=r || j>=c || vis[i][j] || grid[i][j]==0) 
            return 0;
        
        vis[i][j]=true;
        
        int right=travel(i,j+1,r,c,vis,grid);
        int left=travel(i,j-1,r,c,vis,grid);
        int up=travel(i-1,j,r,c,vis,grid);
        int down=travel(i+1,j,r,c,vis,grid);
        
        int maxCollection=max(max(right,left),max(up,down));
        vis[i][j]=false;
        return maxCollection + grid[i][j];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0 , r=grid.size() , c=grid[0].size() ;
        vector<vector<bool>>vis(r,vector<bool>(c,false));
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]){
                    int gold=travel(i,j,r,c,vis,grid);
                    ans=max(ans,gold);
                }
            }
        }
        
        return ans;
    }
};