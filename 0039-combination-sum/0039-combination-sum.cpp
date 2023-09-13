class Solution {
private:
    vector<vector<int>>res;
public:
    void helper(int ind,vector<int>& ds,int target, vector<int>& nums){
        if(target==0) {
            res.push_back(ds);
            return;
        }
        if(target<0) return;
        
        for(int i=ind;i<nums.size();i++){
            
            ds.push_back(nums[i]);
            helper(i,ds,target-nums[i],nums);
            ds.pop_back();
            
            if((target-nums[i])<0) break;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        helper(0,ds,target,nums);
        return res;
    }
};