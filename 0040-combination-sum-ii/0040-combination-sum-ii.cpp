//Re//
//Concept of both, Subsets II + Combination I
//Uses "single recursive call inside for loop" method
class Solution {
    vector<vector<int>>ans;
public:
    void helper(int pos,int target,vector<int>& ds,vector<int>& nums){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        if(pos>=nums.size() || target<0) return;
        for(int i=pos;i<nums.size();i++){
            if(i!=pos && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            target-=nums[i];
            helper(i+1,target,ds,nums);
            ds.pop_back();
            target+=nums[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        helper(0,target,ds,nums);
        
        return ans;
    }
};