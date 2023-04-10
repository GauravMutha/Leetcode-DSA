//Re//
//Concept of both, Subsets II + Combination I
class Solution {
    vector<vector<int>>ans;
public:
    void helper(int i,int target,vector<int>& ds,vector<int>& nums){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        if(i>=nums.size() || target<0) return;
        ds.push_back(nums[i]);
        helper(i+1,target-nums[i],ds,nums);
        ds.pop_back();
        int x=nums[i];
        while(i<nums.size()-1 && x==nums[i+1]) 
            i++;
        helper(i+1,target,ds ,nums);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        helper(0,target,ds,nums);
        
        return ans;
    }
};