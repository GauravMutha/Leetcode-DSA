//Binary search
//O(m*log(n))
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0, end=mat[0].size()-1 , m=mat[0].size();
        while(low<=end){
            int col=low + (end-low)/2;
            int maxElement=0,maxRow=0;
            for(int row=0;row<mat.size();row++){
                if(mat[row][col]>=maxElement)
                    maxRow=row,maxElement=mat[row][col];
            }
            bool leftBig=(col>0)?mat[maxRow][col-1]>maxElement:false;
            bool rightBig=(col<(m-1))?mat[maxRow][col+1]>maxElement:false;
            
            if(!leftBig && !rightBig) return vector<int>{maxRow,col}; 
            else if(rightBig) low=col+1;
            else if(leftBig) end=col-1;
        }
        return {-1,-1}; //execution will never reach here
    }
};