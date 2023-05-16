//Revise
//Binaery Search on matrix
//Single pass binary search on entire matrix
//O(log(m*n)) ~~ O(log(m)+log(n))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size() , c=matrix[0].size();
        int start=0 , end=(r*c)-1,mid=0;
        
        while(start<=end){
            mid=start+(end-start)/2;
            int curr=matrix[mid/c][mid%c];
            if(curr==target) return true;
            else if(curr>target) end=mid-1;
            else if(curr<target) start=mid+1;
        }
        
        return false;
    }
};