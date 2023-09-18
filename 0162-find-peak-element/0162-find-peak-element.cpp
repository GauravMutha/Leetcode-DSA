class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        
        while(low<high){
            int mid=low+(high-low)/2;
            
            if(nums[mid+1]>nums[mid]) low=mid+1;
            else high=mid;
        }
        return low;
    }
};