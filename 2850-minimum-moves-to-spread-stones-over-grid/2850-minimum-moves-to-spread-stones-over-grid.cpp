class Solution {
    private:
    vector<vector<int>>xtras,zeroes;
    int ret=INT_MAX;
public:
    void helper(int ind, int count){
        if(ind>=zeroes.size()){
            ret=min(count,ret);
            return;
        }
        
        for(int k=0;k<xtras.size();k++){
            if(xtras[k][2]==0) continue;
            
            xtras[k][2]--;
            helper(ind+1,abs(xtras[k][0]-zeroes[ind][0])+abs(xtras[k][1]-zeroes[ind][1])+count);
            xtras[k][2]++;
        }
    }
    int minimumMoves(vector<vector<int>>& grid) {
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==0) zeroes.push_back({i,j});
                else if(grid[i][j]>1) xtras.push_back({i,j,grid[i][j]-1});
            }
        }
        if(zeroes.empty()) return 0;
        helper(0,0);
        return ret;
    }
};