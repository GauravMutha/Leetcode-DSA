//Revise
class Solution {
public:
    vector<vector<int>>res;
    void helper(vector<int>& ds,vector<int>& nums,vector<bool>& visited){
        if(ds.size()==nums.size()){
            res.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]) continue;
            visited[i]=true;
            ds.push_back(nums[i]);
            helper(ds,nums,visited);
            visited[i]=false;
            ds.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>visited(nums.size(),false);
        vector<int>ds;
        helper(ds,nums,visited);
        return res;
    }
};