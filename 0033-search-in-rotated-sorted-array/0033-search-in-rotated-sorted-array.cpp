class Solution {
private:
    int findFactor(vector<int>& nums) {
        int low=0,high=nums.size()-1,ans=0;
        while(low<high){
            int mid=low+(high-low)/2;
            
            if(nums[mid]>nums[high]) low=mid+1;
            else high=mid;
        }
        return low;
    }
public:
    int search(vector<int>& nums, int target) {
        //k is right shift factor
        int k=findFactor(nums),n=nums.size();
        int low=0,high=nums.size()-1;
        
        while(low<=high){
            int mid=low+ (high-low)/2;
            
            if(nums[(mid+k)%n]==target) return (mid+k)%n;
            else if(nums[(mid+k)%n]<target) low=mid+1;
            else high=mid-1;
        }
        
        return -1;
    }
};