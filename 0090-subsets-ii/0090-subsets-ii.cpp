class Solution {
private:
    vector<vector<int>>res;
public:
    void helper(int ind,vector<int>& ds,vector<int>& nums){
        res.push_back(ds);
        
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            
            ds.push_back(nums[i]);
            helper(i+1,ds,nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        helper(0,ds,nums);
        
        return res;
    }
};