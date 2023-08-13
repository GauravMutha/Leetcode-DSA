class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size(),res=0;
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        for(int ind1=1;ind1<=n1;ind1++){
            for(int ind2=1;ind2<=n2;ind2++){
                if(nums1[ind1-1]!=nums2[ind2-1]) continue;
                dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                res=max(dp[ind1][ind2],res);
            }
        }
        
        return res;
    }
};