class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        int sz=nums.size();
        
        for(int x=0;x<pow(2,sz);x++){
            vector<int>ds;
            for(int i=0;i<sz;i++){
                if((1<<i)&x) ds.push_back(nums[i]);
            }
            res.push_back(ds);
        }
        
        return res;
    }
};