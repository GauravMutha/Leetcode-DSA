class Solution {
public:
int matrixScore(vector<vector<int>>& grid) {
    //TC-->O(m*n) SC-->O(n)
    //Two pass solution + No need for column toggling thus reducing time
        int m=grid.size();
        int n=grid[0].size();
        vector<int>vect(n,0);
        int total=0;
        //row toggle
        for(int i=0;i<m;i++){
            if(grid[i][0]==0){
                for(int j=0;j<n;j++){
                    grid[i][j]=(!grid[i][j])?1:0;
                    vect[j]+=grid[i][j];
                }
            }
            else{
                for(int j=0;j<n;j++){
                    vect[j]+=grid[i][j];
                } 
            }
        }
        //column toggle
        for(int k=0;k<n;k++){
         if(vect[k]<=(m/2))
             vect[k]=m-vect[k];
         total+=pow(2,n-k-1)*vect[k];
        }
        return  total;
    }
};