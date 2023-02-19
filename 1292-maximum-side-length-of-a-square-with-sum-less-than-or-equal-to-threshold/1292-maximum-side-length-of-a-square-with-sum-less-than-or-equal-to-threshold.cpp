//Binary search + prefix sum (DP-type)
class Solution {
private:
    int m=0,n=0;
    bool squareExists(vector<vector<int>>&prefixSum,int len,int k){
        for(int i=len;i<=m;i++){
            for(int j=len;j<=n;j++){
                if(prefixSum[i][j]-prefixSum[i-len][j]-prefixSum[i][j-len]+prefixSum[i-len][j-len]<=k)
                    return true;
            }
        }
        return false;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        m=mat.size() , n=mat[0].size();
        vector<vector<int>>prefixSum(m+1,vector<int>(n+1));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                prefixSum[i][j]=prefixSum[i-1][j]+prefixSum[i][j-1]-prefixSum[i-1][j-1]+mat[i-1][j-1];
            }
        }
        
        int low=1,end=max(m,n),ans=0;
        
        while(low<=end){
            int mid=low+(end-low)/2;
            
            if(squareExists(prefixSum,mid,threshold)) ans=mid , low=mid+1;
            else end=mid-1;
        }
        
        return ans;
    }
};