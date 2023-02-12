//sliding window
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size(),res=0,zeroes=0;
        while(r<n){
            if(nums[r]==0) zeroes++;
            while(l<=r && zeroes>k){
                if(nums[l]==0) zeroes--;
                l++;
            }
            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};