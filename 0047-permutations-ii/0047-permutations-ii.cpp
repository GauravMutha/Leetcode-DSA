//Re//
//Swapping method
class Solution {
private:
vector<vector<int>>ans;
public:
    void helper(int pos,vector<int>& nums){
        if(pos>=nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_map<int,bool> vis;
        for(int i=pos;i<nums.size();i++){
            if(vis.find(nums[i])!=vis.end()) continue;
            vis[nums[i]]=true;
            swap(nums[i],nums[pos]);
            helper(pos+1,nums);
            swap(nums[i],nums[pos]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        helper(0,nums);
        
        return ans;
    }
};