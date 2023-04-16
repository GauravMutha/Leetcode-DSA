//Using simple backtracking
//Similar to subset II
//Using set for avoiding dupliacte element at same level of recursion
class Solution {
private:
    vector<vector<int>>ans;
public:
    void helper(int pos, vector<int>& ds,vector<int>& nums){
        if(ds.size()>=2){
            ans.push_back(ds);
        }
        set<int>taken;
        for(int i=pos;i<nums.size();i++){
            if(taken.count(nums[i]) || (ds.size()>0 && ds.back()>nums[i]))
                continue;
            taken.insert(nums[i]);
            ds.push_back(nums[i]);
            helper(i+1,ds,nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>ds;
        helper(0,ds,nums);
        
        return ans;
    }
};