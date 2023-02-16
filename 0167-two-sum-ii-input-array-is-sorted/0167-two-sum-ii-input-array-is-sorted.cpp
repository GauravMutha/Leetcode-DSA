//two pinters 
//O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        int r=nums.size()-1,l=0;
        
        while(l<r){
            if(long(nums[l]+nums[r])==k) return {l+1,r+1};
            
            else if(long(nums[l]+nums[r])>k) r--;
            else l++;
        }
        
        return {};
    }
};