class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> res;
        int ind=0;
        
        generate(res,0,nums);
        return res;
        
    }
    
    void generate(vector<vector<int>>& res,int ind,vector<int>& nums){
        static vector<int>ds;
        if(ind==nums.size()){
            res.push_back(ds);
            return;
        }

        ds.push_back(nums[ind]);
        generate(res,ind+1,nums);
        ds.pop_back();
        
        while(ind+1<nums.size() && (nums[ind]==nums[ind+1]))ind++;
        generate(res,ind+1,nums);
    }
};