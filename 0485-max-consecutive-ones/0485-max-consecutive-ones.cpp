class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,maxCount=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                maxCount=max(count,maxCount);
                count=0;
            }
            else count++;
        }
        return max(count,maxCount);
    }
};