//Re//
//Using a for loop in helper
//sorting
class Solution {
private:
    vector<vector<int>>ans;
public:
    void helper(int ind,int sum,vector<int>& ds,vector<int>& nums,int k){
        if(sum>=k){
            if(sum==k) ans.push_back(ds);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            sum+=nums[i];
            ds.push_back(nums[i]);
            helper(i,sum,ds,nums,k);
            sum-=nums[i];
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        helper(0,0,ds,nums,target);
        return ans;
    }
};