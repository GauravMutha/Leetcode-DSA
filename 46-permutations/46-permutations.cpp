class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        perm(nums,res,0);
        return res;
    }
    
    void perm(vector<int>& nums,vector<vector<int>>& res,int ind){
        if(ind==nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            perm(nums,res,ind+1);
            swap(nums[i],nums[ind]);
        }
    }
};