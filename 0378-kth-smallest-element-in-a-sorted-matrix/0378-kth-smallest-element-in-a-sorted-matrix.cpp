//min heap 
//kth smallest amongst m sorted rows
//SC-->O(N)
//TC-->O((n+k)*logn)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<>> minh;
        vector<int>vec;
        //n equal to matrix[0].size() too as it is nXn matrix
        int n=matrix.size(),ans=0; 
        for(int r=0;r<min(n,k);r++)
            minh.push({matrix[r][0],r,0});
        
        while(k--){
            vec=minh.top(), minh.pop();
            ans=vec[0];
            int currR=vec[1];
            int currCol=vec[2];
            if(currCol+1 < n)
                minh.push({matrix[currR][currCol+1],currR,currCol+1});
        }
        
        return ans;
    }
};