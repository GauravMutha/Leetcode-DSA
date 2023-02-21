//Easier than its first version!!
//O(M+N)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size() , n=mat.size();
        int r=0 , c=mat[0].size()-1; //starting from top right corner
        while(c>=0 && r<m){
            if(mat[r][c]==target) return true;
            if(mat[r][c]>target) c--;
            else r++;
        }
        return false;
    }
};