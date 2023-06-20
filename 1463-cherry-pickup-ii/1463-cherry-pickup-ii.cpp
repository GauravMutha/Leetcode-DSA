//Tabulation
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size();
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        for(int j1=0;j1<c;j1++){
            for(int j2=0;j2<c;j2++){
                if(j1==j2) dp[r-1][j1][j2]=grid[r-1][j1];
                else dp[r-1][j1][j2]=grid[r-1][j1]+grid[r-1][j2];
            }
        }
        
        for(int i=r-2;i>=0;i--){
            for(int j1=0;j1<c;j1++){
                for(int j2=0;j2<c;j2++){
                    int maxVal=INT_MIN;
                    for(int dj1=-1;dj1<=1;dj1++){
                        for(int dj2=-1;dj2<=1;dj2++){
                            int val=0;
                            if(j1==j2) val=grid[i][j1];
                            else val=grid[i][j1]+grid[i][j2];
                            if((j1+dj1)>=0 && (j2+dj2)>=0 && (j1+dj1)<c &&(j2+dj2)<c)
                                val+=dp[i+1][j1+dj1][j2+dj2];
                            else val=-1e8;
                            maxVal=max(maxVal,val);
                        }
                    }
                    dp[i][j1][j2]=maxVal;
                }
            }
        }
        return  dp[0][0][c-1];
    }
};