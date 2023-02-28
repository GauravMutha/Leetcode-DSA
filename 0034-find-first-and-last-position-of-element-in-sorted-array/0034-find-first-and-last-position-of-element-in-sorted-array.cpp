class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb=-1,ub=-1;
        
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(nums[mid]==target) lb=mid;
            if(nums[mid]>=target) high=mid-1;
            else low=mid+1;
        }
        if(lb==-1) return vector<int>{-1,-1};
        low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(nums[mid]==target) ub=mid;
            if(nums[mid]<=target) low=mid+1;
            else high=mid-1;
            
        }
        
        return vector<int>{lb,ub};
    }
};