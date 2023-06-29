//BFS
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size() , n=grid[0].size() ,freshCount=0,time=0;
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) freshCount++;
            }
        }
        
        while(q.size() && freshCount){
            int sz=q.size();
            time++;
            
            for(int i=0;i<sz;i++){
                
                int r=q.front().first , c=q.front().second;
                q.pop();
                
                if(r+1<m  && grid[r+1][c]==1){
                    grid[r+1][c]=2;
                    q.push({r+1,c});
                    freshCount--;
                }
                if(c+1<n  && grid[r][c+1]==1){
                    grid[r][c+1]=2;
                    q.push({r,c+1});
                    freshCount--;
                }
                if(r-1>=0  && grid[r-1][c]==1){
                    grid[r-1][c]=2;
                    q.push({r-1,c});
                    freshCount--;
                }
                if(c-1>=0  && grid[r][c-1]==1){
                    grid[r][c-1]=2;
                    q.push({r,c-1});
                    freshCount--;
                }
            }
        }
        if(freshCount) return -1;
        return time;
    }
};