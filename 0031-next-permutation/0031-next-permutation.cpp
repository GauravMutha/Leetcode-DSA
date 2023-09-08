//Striver 79 sheet
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int sz=nums.size(), i=sz-1;
        while(i>0 && nums[i]<=nums[i-1]) i--;
        reverse(nums.begin()+i,nums.end());
        if(i==0) return;
        int k=i-1;
        while(i<sz && nums[i]<=nums[k]) i++;
        swap(nums[k],nums[i]);
        return;
    }
};