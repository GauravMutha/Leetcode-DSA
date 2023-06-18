class Solution {
public:
    int rotationFactor(vector<int>&nums){
        int low=0 , high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums.back()) low=mid+1;
            //below ot is not mid-1 because what if mid itself is the minima?{5,1,3}
            else high=mid;
        }
        return low;
    }
    int search(vector<int>& nums, int target) {
        int k=rotationFactor(nums), n=nums.size();
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[(mid+k)%n]==target) return (mid+k)%n;
            else if(nums[(mid+k)%n]<target) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
};