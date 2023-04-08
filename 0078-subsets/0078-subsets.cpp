//Re//
//Iterative
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        ans.push_back({});
        
        for(auto num : nums){
            int n=ans.size();
            vector<int>ds;
            for(int i=0;i<n;i++){
                ds=ans[i];
                ds.push_back(num);
                ans.push_back(ds);
            }
        }
        return ans;
    }
};