//Re//
//using swapping method
class Solution {
private:
    vector<vector<int>>ans;
public:
    void helper(int pos,vector<int>& nums){
        if(pos>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=pos;i<nums.size();i++){
            swap(nums[i],nums[pos]);
            helper(pos+1,nums);
            swap(nums[i],nums[pos]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(0,nums);
        
        return ans;
    }
};