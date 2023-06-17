//Using prefix and suffix array method
class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size(),res=0;
        vector<int>pre(n,nums[0]) , suff(n,nums[n-1]);
        for(int i=1,j=n-2;i<n && j>=0;i++,j--){
            pre[i]=max(pre[i-1],nums[i]);
            suff[j]=max(suff[j+1],nums[j]);
        }
        for(int i=0;i<n;i++){
            res+=(min(pre[i],suff[i])-nums[i]);
        }
        return res;
    }
};