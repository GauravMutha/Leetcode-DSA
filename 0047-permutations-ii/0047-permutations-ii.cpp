//Re//
//visited array method (+sorting)
class Solution {
private:
vector<vector<int>>ans;
public:
    void helper(vector<int>& ds,vector<bool>& visited,vector<int>& nums){
        if(ds.size()>=nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(visited[i]) continue;
            if(i>0 && nums[i]==nums[i-1] && visited[i-1]) continue;
//so we take the duplicate only if its previous similar element has been taken
            visited[i]=true;
            ds.push_back(nums[i]);
            helper(ds,visited,nums);
            visited[i]=false;
            ds.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<bool>visited(nums.size());
        vector<int>ds;
        helper(ds,visited,nums);
        
        return ans;
    }
};