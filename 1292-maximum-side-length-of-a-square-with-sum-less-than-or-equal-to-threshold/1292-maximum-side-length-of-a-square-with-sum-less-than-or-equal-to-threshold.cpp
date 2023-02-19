//Only prefix sum - No binary search
//O(m*n)
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size() , n=mat[0].size();
        vector<vector<int>>preSum(m+1,vector<int>(n+1));
        int ans=0, len=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                preSum[i][j]=preSum[i-1][j]+preSum[i][j-1]-preSum[i-1][j-1]+mat[i-1][j-1];
                
                if(i>=len && j>=len && preSum[i][j]-preSum[i-len][j]-preSum[i][j-len]+preSum[i-len][j-len]<=threshold){
                    ans=len;
                    len++;
                }
            }
        }
        return ans;
    }
};