class Solution {
public:
    vector<int> sortByBits(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>res;
        vector<vector<int>> vec(32,vector<int>());
        
        for(auto num : nums){
            vec[__builtin_popcount(num)].push_back(num);
        }
        
        for(int i=0;i<32;i++){
            for(int j=0;j<vec[i].size();j++)
                res.push_back(vec[i][j]);
        }
        
        return res;
    }
};