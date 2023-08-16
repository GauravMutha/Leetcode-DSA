class Solution {
private:
    queue<pair<int,int>>q;//island1 nodes
    vector<int>dirs{0,-1,0,1,0};
    
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        if(i<0 || j <0 || i>=grid.size() || j>=grid.size() || vis[i][j] || grid[i][j]==0) return;
        
        q.push({i,j});
        vis[i][j]=true;
        
        for(int k=0;k<(dirs.size()-1);k++)
            dfs(i+dirs[k],j+dirs[k+1],grid,vis);
        
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        bool islandFound=false;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        
        //first find island1
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                dfs(i,j,grid,vis);
                islandFound=true;
                break;
            }
            if(islandFound==true) break;
        }
        
        //land expansion of island1 using multi source bfs,to find island2
        int steps=0;
        while(q.size()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto p=q.front();
                q.pop();
                for(int k=0;k<(dirs.size()-1);k++){
                    int r=p.first+dirs[k], c=p.second+dirs[k+1];
                    if(r<0 || c<0 || r>=n || c>=n || vis[r][c]) continue;
                    if(grid[r][c]==1) return steps;
                    q.push({r,c});
                    vis[r][c]=true;
                }
            }
            steps++;
        }
        return -1;
    }
};