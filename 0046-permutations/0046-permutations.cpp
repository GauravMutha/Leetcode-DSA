//Re//
//using visited array method
class Solution {
private:
    vector<vector<int>>ans;
public:
    void helper(vector<int>& ds,vector<bool>& vis,vector<int>& nums){
        if(ds.size()>=nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i]) continue;
            
            vis[i]=true;
            ds.push_back(nums[i]);
            
            helper(ds,vis,nums);
            
            vis[i]=false;
            ds.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ds;
        vector<bool>visited(nums.size());
        helper(ds,visited,nums);
        
        return ans;
    }
};