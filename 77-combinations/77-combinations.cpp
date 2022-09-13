class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums(n,0);
        vector<vector<int>>res;
        
        for(int i=1;i<=n;i++)
            nums[i-1]=i;
        
        gen(nums,res,0,k);
        
        return res;
    }
    
    void gen(vector<int>& nums,vector<vector<int>>& res,int i,int k){
        static vector<int> ds;
        
        if(ds.size()==k){
            res.push_back(ds);
            return;
        }
        if(i==nums.size()){
            return;
        }
        
        ds.push_back(nums[i]);
        gen(nums,res,i+1,k);
        ds.pop_back();
        gen(nums,res,i+1,k);
    }
};