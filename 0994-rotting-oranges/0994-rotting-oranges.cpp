class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dir[5]={0,1,0,-1,0};
        int time=0, fresh=0, m=grid.size(), n=grid[0].size();
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }
        
        while(q.size() && fresh){
            int sz=q.size();
            time++;
            while(sz--){
                auto cell=q.front(); q.pop();
                
                for(int k=0;k<4;k++){
                    int r=cell.first+dir[k], c= cell.second+dir[k+1];
                    if(r<0 || c<0 || r>=m || c>=n || grid[r][c]==0 || grid[r][c]==2) continue;
                    fresh--;
                    grid[r][c]=2;
                    q.push({r,c});
                }
            }
        }
        return (fresh>0) ? -1 : time;
    }
};