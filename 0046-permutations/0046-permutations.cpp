//Revise
class Solution {
public:
    vector<vector<int>>res;
    void helper(int ind,vector<int>& nums){
        if(ind>=nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            helper(ind+1,nums);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(0,nums);
        return res;
    }
};