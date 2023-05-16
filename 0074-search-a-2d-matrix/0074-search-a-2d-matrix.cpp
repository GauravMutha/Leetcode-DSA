//REVISE
//Binary search without using STL method
//log(n)+log(m)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(),c=matrix[0].size();
        
        int start=0,end=r-1,mid=0;
        // binary seach  on last column to select the row
        while(start<=end){
            mid=start+(end-start)/2;
            if(matrix[mid][c-1]==target) return true;
            else if(matrix[mid][c-1]>target) end=mid-1;
            else if(matrix[mid][c-1]<target) start=mid+1;
        }
        int i=start;
        if(i>=r) return false; //no row can contain the target
        
        //binary search on selected ith row
        start=0 , end=c-1 , mid=0;
        
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