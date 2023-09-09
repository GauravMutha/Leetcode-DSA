class Solution {
public:
    vector<vector<int>>res;
    void helper(int ind, vector<int>& ds, vector<int>& nums){
        if(ind==nums.size()){
            res.push_back(ds);
            return;
        }
        
        ds.push_back(nums[ind]);
        helper(ind+1,ds,nums);
        
        ds.pop_back();
        helper(ind+1,ds,nums);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        helper(0,ds,nums);
        return res;
    }
};