//Re//
//Sorting but the backtracking is slightly different
class Solution {
private:
    vector<vector<int>>ans;
public:
    void helper(int pos,vector<int>& ds, vector<int>& nums){
        ans.push_back(ds);
        for(int i=pos;i<nums.size();i++){
            if(i!=pos && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            helper(i+1,ds,nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        /*
        Although we apply subsequence approach of pick or
        not pick but the question is of subsets so we can
        sort nums.
        */
        sort(nums.begin(),nums.end());
        vector<int>ds;
        
        helper(0,ds,nums);
        
        return ans;
    }
};