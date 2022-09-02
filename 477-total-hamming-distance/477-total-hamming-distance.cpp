class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result=0,count=0;
        for(int i=0;i<32;i++){
            count=0;
            for(int j=0;j<nums.size();j++){
                count+=(nums[j]>>i)&1;
            }
            result+=(count*(nums.size()-count));
        }
        return result;
    }
};