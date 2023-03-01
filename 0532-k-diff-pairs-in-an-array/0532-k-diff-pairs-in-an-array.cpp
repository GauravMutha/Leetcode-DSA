// sort + Binary search
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count=0,n=nums.size(),j=0,target=0;
        sort(begin(nums),end(nums));
        for(int i=0;i<n-1;i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            int target=nums[i]+k;
            int j=lower_bound(begin(nums)+i+1,end(nums),target)-begin(nums);
            if(j<n && nums[j]==target) count++; 
        }
        
        return count;
    }
};