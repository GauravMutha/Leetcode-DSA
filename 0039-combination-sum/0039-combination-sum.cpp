//Re//
//classic two recursive calls for pick and not pick
//no for loops
class Solution {
private:
    vector<vector<int>>ans;
public:
    void helper(int i,int target,vector<int>& ds,vector<int>& nums){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        if(target<0 || i>=nums.size()) return;
        
        
        ds.push_back(nums[i]);
        helper(i,target-nums[i],ds,nums);
        ds.pop_back();
        helper(i+1,target,ds,nums);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        helper(0,target,ds,nums);
        return ans;
    }
};