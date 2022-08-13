class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        backtrack(nums,0);
        return ans;
    }
    void backtrack(vector<int>&nums,int i){
        static vector<int>ds;
        if(i==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        backtrack(nums,i+1);
        ds.pop_back();
        backtrack(nums,i+1);
    }
};