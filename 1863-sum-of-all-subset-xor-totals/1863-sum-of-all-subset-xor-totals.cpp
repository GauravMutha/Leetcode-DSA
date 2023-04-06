//>>>//

class Solution {
public:
    int subsetXORSum(vector<int>& nums,int i=0,int sum=0) {
        
        if(i>=nums.size()){
            return sum;
        }
        sum^=nums[i];
        int sumIfPicked=subsetXORSum(nums,i+1,sum);
        sum^=nums[i]; //XORing with the same number is equivalent to popping
        int sumIfNotPicked=subsetXORSum(nums,i+1,sum);
        
        return sumIfPicked + sumIfNotPicked;
    }
};