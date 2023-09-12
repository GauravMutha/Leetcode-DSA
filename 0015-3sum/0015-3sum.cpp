class Solution {
private:
    int n=0;
    vector<vector<int>>res;
public:
    int binarySearch(int low,vector<int>& nums, int target){
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
    void twoSum(int start,vector<int>& nums, int target){
        for(int i=start;i<n-1;i++){
            if(i>start && nums[i]==nums[i-1]) continue;
            int k=binarySearch(i+1,nums,target-nums[i]);
            if(k==-1) continue;
            res.push_back(vector<int>({-target,nums[i],nums[k]}));
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        int target=0; //target for the triplets is 0 actually
        for(int i=0;i<n-2;i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            twoSum(i+1,nums,target-nums[i]);
        }
        
        return res;
    }
};