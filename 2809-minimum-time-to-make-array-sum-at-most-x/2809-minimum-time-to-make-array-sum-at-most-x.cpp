class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n=nums1.size();
        
        int sum1=accumulate(nums1.begin(),nums1.end(),0);
        int sum2=accumulate(nums2.begin(),nums2.end(),0);
        
        if(sum1<=x) return 0;
        
        vector<pair<int,int>>vec(n);
        for(int i=0;i<n;i++) vec[i]=make_pair(nums2[i],nums1[i]);
        sort(vec.begin(),vec.end());
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        
        for(int t=1;t<=n;t++){
            for(int i=1;i<=n;i++){
                dp[i][t]=max(dp[i-1][t], vec[i-1].first*t+vec[i-1].second+dp[i-1][t-1]);
            }
        }
        
        for(int t=1;t<=n;t++){
            int sum=sum1+t*sum2;
            if((sum-dp[n][t])<=x) return t;
        }
        
        return -1;
    }
};