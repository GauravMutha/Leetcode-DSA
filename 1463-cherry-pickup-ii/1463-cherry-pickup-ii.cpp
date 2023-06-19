//Memoization
class Solution {
private:
    int r,c;
public:
    //j1 for alice and j2 for bob
    int helper(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(j1<0 || j2<0 || j1>=c || j2>=c) return INT_MIN;
        if(i==(r-1)){
            if(j1==j2) return grid[i][j1];
            else return (grid[i][j1]+grid[i][j2]);
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        
        int maxVal=INT_MIN;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int val=0;
                if(j1==j2) val=grid[i][j1];
                else val=grid[i][j1]+grid[i][j2];
                val+=helper(i+1,j1+dj1,j2+dj2,grid,dp);
                maxVal=max(maxVal,val);
            }
        }
        
        return dp[i][j1][j2]=maxVal;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        r=grid.size(), c=grid[0].size();
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));

        return  helper(0,0,c-1,grid,dp);
    }
};