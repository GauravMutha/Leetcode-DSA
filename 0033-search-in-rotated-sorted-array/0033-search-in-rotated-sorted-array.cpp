class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            double x;
            if((nums[mid]<nums[0]) == (target<nums[0])) x=nums[mid];
            else if(target<nums[0]) x=-INFINITY;
            else if(target>=nums[0]) x=+INFINITY;
            
            if(target==x) return mid;
            else if(x<target) start=mid+1;
            else if(x>target) end=mid-1;
        }
        return -1;
    }
};