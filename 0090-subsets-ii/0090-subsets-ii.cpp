class Solution {
public:
    vector<vector<int>>res;
    void helper(int ind,vector<int>& ds,vector<int>& nums){
        
        if(ind>=nums.size()){
            res.push_back(ds);
            return;
        }
        
        ds.push_back(nums[ind]);
        helper(ind+1,ds,nums);
        
        ds.pop_back();
        int val=nums[ind];
        while(ind<nums.size() && nums[ind]==val) ind++;
        helper(ind,ds,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ds;
        sort(nums.begin(),nums.end());
        helper(0,ds,nums);
        return res;
    }
};