class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()<3) return true;
        
        bool inc=true, dec=true;
        // check for increasing
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=nums[i-1]) continue;
            inc=false;
            break;
        }
        // check for increasing
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]) continue;
            dec=false;
            break;
        }
        
        
        
        return (inc || dec);
    }
};