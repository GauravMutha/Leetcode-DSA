class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result=0,mask=1,count=0;
        for(int i=0;i<32;i++){
            mask=(1<<i);count=0;
            for(int j=0;j<nums.size();j++){
                if(mask&nums[j])count++;
            }
            result+=(count*(nums.size()-count));
        }
        return result;
    }
};