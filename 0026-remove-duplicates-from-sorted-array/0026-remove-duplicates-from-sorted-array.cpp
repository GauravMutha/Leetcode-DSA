class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(), l=0,r=0,prev=-101;
        
        for(r=0;r<n;r++){
            if(nums[r]==prev) continue;
            nums[l]=nums[r];
            prev=nums[r];
            l++;
        }
        
        return l;
    }
};