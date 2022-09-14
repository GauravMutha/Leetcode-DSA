class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxgold=0;
        vector<bool>vec(n,false);
        vector<vector<bool>>visited(m,vec);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    int sum=travel(grid,visited,i,j);
                    
                    maxgold=max(sum,maxgold);
                }
            }
        }
        return maxgold;
    }
    
    int travel(vector<vector<int>>& grid,vector<vector<bool>>& visited,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || visited[i][j]==true || grid[i][j]==0)
            return 0;
        
        visited[i][j]=true;
        
        int down= travel(grid,visited,i+1,j);
        int left= travel(grid,visited,i,j-1);
        int right= travel(grid,visited,i,j+1);
        int up= travel(grid,visited,i-1,j);
        
        visited[i][j]=false;
        return max(down,max(left,max(up,right)))+grid[i][j];
    }
};