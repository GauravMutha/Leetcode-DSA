class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        for(int x=0;x<pow(2,n);x++){
            vector<int>ele={};
            for(int i=0;i<n;i++){
                if(x&(1<<i))ele.push_back(nums[i]);
            }
            ans.push_back(ele);
        }
        return ans;
    }
};