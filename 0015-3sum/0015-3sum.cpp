//O(n^2*(log(n)))
//better than O(n^3)
class Solution {
private:
    vector<vector<int>>res;
public:
    int binarySearch(int j,int target, vector<int>& nums){
    int start=j+1,end=nums.size()-1,mid=0;
    while(start<=end){
        mid=start+(end-start)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) end=mid-1; 
        else if(nums[mid]<target) start=mid+1; 
    }
    
    return -1;
    }
    void twoSum(vector<int>& nums, int target,int i) {
        for(int j=i+1;j<nums.size();j++){
            if(j>(i+1) && (nums[j]==nums[j-1]) ) continue;
            int k=binarySearch(j,target-nums[j],nums);
            if(k!=-1) res.push_back({-target,nums[j],nums[k]});
        }
        
        return;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && (nums[i]==nums[i-1]) ) continue;
            int target=-nums[i];
            twoSum(nums,target,i);
        }
        
        return res;
    }
};