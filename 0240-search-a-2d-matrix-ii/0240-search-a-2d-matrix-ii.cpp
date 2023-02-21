//Binary search
//O(m*log(n))
class Solution {
private :
    int m=0,n=0;
    bool foundTarget(vector<vector<int>>& mat,int row,int target){
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+ (high-low)/2;
            
            if(mat[row][mid]==target) return true;
            else if(mat[row][mid]<target) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        m=mat.size(),n=mat[0].size();
        
        for(int r=0;r<m;r++){
            if(foundTarget(mat,r,target)) return true;
        }
        return false;
    }
};