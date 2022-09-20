class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        perm(0,nums,ans);
        
        return ans;
    }
    
    void perm(int index,vector<int>nums,vector<vector<int>>& ans){
        
        if(index==nums.size()){
            return ans.push_back(nums);
        }
        unordered_set<int>s;
        for(int i=index;i<nums.size();i++){
            if(s.find(nums[i])!=s.end())continue;
            s.insert(nums[i]);
            swap(nums[index],nums[i]);
            perm(index+1,nums,ans);
            swap(nums[index],nums[i]);
        }
    }
};