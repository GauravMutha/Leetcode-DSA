class Solution {
public:
    int trap(vector<int>& heights) {
        int res=0,n=heights.size();
        vector<int>prefix(n,heights[0]),suffix(n,heights.back());
        
        for(int i=1,j=n-2;i<n && j>=0;i++,j--){
            prefix[i]=max(prefix[i-1],heights[i]);
            suffix[j]=max(suffix[j+1],heights[j]);
        }
        
        for(int i=1;i<n-1;i++)
            res+=(min(prefix[i],suffix[i])-heights[i]);
        
        return res;
    }
};