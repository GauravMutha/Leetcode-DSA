//Re//
//A slightly different implementation of backtracking
class Solution {
private:
    vector<vector<int>>ans;
public:
    void helper(int pos,vector<int>& ds,vector<int>& nums){
        ans.push_back(ds);
        for(int i=pos;i<nums.size();i++){
            ds.push_back(nums[i]);
            helper(i+1,ds,nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        helper(0,ds,nums);
        
        return ans;
    }
};