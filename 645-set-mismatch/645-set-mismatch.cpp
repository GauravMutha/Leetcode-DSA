class Solution {
public:
   vector<int> findErrorNums(vector<int>& nums) {
       vector<int>ans;
        for(int i = 0; i<nums.size(); i++){
            while(nums[i] != nums[nums[i] - 1])swap(nums[i], nums[nums[i] - 1]);
        }
        for(int i = 0; i<nums.size() ; i++){
            if(nums[i] != i + 1){ans={nums[i], i + 1}; break;}
        }
       return ans;
    }
};