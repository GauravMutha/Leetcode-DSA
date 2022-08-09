class Solution {
public:
int matrixScore(vector<vector<int>>& grid) {
    //TC-->O(m*n) SC-->O(n)
        int m=grid.size();
        int n=grid[0].size();
        vector<int>vect(n,0);
        //row toggle
        for(int i=0;i<m;i++){
            if(grid[i][0]==0){
                for(int j=0;j<n;j++){
                    grid[i][j]=(!grid[i][j])?1:0;
                }
            }
        }
        for(int j=0;j<n;j++){
            int count=0;
            for(int i=0;i<m;i++){
                if(grid[i][j]==1)count++;
            }
            if(count>m/2)vect[j]++;
        }
        //column toggle
        for(int j=0;j<n;j++){
            if(!vect[j]){
                for(int i=0;i<m;i++){
                    grid[i][j]=(!grid[i][j])?1:0;     
                }
            }
        }
        int total=0;
        for(int i=0;i<m;i++){
            int num=0;
            for(int j=0;j<n;j++){
                num+=pow(2,n-1-j)*grid[i][j];
            }
            total+=num;
        }
        return total;
    }
};