//Using Hash Map 
//TC--> O(N)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int>res;
        unordered_map<int,vector<int>>m;
        int maxSum=INT_MIN,rows=nums.size();
        for(int r=rows-1;r>=0;r--){
            for(int c=0;c<nums[r].size();c++){
                m[r+c].push_back(nums[r][c]);
                maxSum=max(r+c,maxSum);
            }
        }
        
        for(int sum=0;sum<=maxSum;sum++){
            for(auto &value : m[sum]) 
                res.push_back(value);  
        }
        
        return res;
    }
};