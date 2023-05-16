//REVISE
//Binary search
//n+logm
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size() , c=matrix[0].size();
        // choosing row
        int i=0;
        for(i=0;i<r;i++){
            if(matrix[i][c-1]>target)
                break;
            else if(matrix[i][c-1]==target) return true;
        }
        if(i>=r) return false; //no row can contain the target
        
        //performing binary search on chosen ith row
        int start=0 , end=c-1 , mid=0;
        
        while(start<=end){
            mid= start+ (end-start)/2;
            int curr=matrix[i][mid];
            if(curr==target) return true;
            else if(curr<target) start=mid+1;
            else if(curr>target) end=mid-1;
        }
        return false;
    }
};