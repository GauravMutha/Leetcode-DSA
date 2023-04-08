//Simple concept of "to pick or to not pick"
class Solution {        
private:
vector<vector<int>>ans;

public:
    void helper(int i, vector<int>& ds,vector<int>& nums){
        if(i>=nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        helper(i+1,ds,nums);
        ds.pop_back();
        helper(i+1,ds,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        
        helper(0,ds,nums);
        
        return ans;
    }
};