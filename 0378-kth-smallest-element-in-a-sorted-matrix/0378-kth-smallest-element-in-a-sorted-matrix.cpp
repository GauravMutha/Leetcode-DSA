//O((n+n)*log(diff))
// diff is the difference between minimum and maximum element of matrix
//or simply the search space length in which we ar apllying binary search
class Solution {
private:
    int countLessOrEqual(vector<vector<int>>& matrix,int x){
        int col=matrix.size()-1,count=0;
        for(int row=0;row<matrix.size();row++){
            while(col>=0 && matrix[row][col]>x) col--;
            count+=(col+1); // because col is an index of zero indexed based matrix
        }
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(), ans=0;
        int start=matrix[0][0] , end=matrix[m-1][m-1] , mid=0;
        
        while(start<=end){
            mid=(end+start)/2;
            if(countLessOrEqual(matrix,mid)>=k){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        
        return ans;
    }
};