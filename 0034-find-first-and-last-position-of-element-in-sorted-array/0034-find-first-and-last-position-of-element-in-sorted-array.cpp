//concise than previous
class Solution {
private:
    int lowerBound(vector<int>&nums,int k){
        int low=0,high=nums.size()-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(nums[mid]>=k) high=mid-1;
            else low=mid+1;
        }
        
        return low;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb=lowerBound(nums,target);
        if(lb>=nums.size() || nums[lb]!=target) return vector<int>{-1,-1};
        int ub=lowerBound(nums,target+1)-1;
        
        return vector<int>{lb,ub};
    }
};