//Revise
//Zig Zag method  / starting from top right corner
//O(m) or O(n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size() , c=matrix[0].size();
        int i=0 , j=c-1;
        while(i<r && j<c && i>=0 && j>=0){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) j--;
            else if(matrix[i][j]<target) i++;
        }
        
        return false;
    }
};