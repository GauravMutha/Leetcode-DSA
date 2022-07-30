class Solution {
public:
    bool divideArray(vector<int>& nums) {
        //TC--->O(nlogn)
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-1;){
            if(nums[i]==nums[i+1])
                i+=2;
            else
                return false;
        }
        
        return true;
        
    }
};