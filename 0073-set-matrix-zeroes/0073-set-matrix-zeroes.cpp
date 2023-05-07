//Worst case space complexity is O(m+n)
//TC-->O(m*n)
//2 pass
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        set<int>rowBan,colBan;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0)
                    rowBan.insert(i) , colBan.insert(j);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rowBan.count(i) || colBan.count(j))
                    matrix[i][j]=0;
            }
        }
        
        return;
    }
};