class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();){
            while((nums[i]-1)==i) i++;
            if(nums[nums[i]-1]==nums[i]) return nums[i];
            swap(nums[nums[i]-1],nums[i]);
        }
        return 1;
    }
};