//Re//
//Sorting
class Solution {
private:
    vector<vector<int>>ans;
public:
    void helper(int i,vector<int>& ds, vector<int>& nums){
        if(i>=nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        helper(i+1,ds,nums);
        ds.pop_back();
        int x=nums[i];
        while(i<nums.size()-1 && x==nums[i+1]) 
            i++;
        helper(i+1,ds,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        /*
        Although we apply subsequence approach of pick or
        not pick but the question is of subsets so we can
        sort nums.
        */
        sort(nums.begin(),nums.end());
        vector<int>ds;
        
        helper(0,ds,nums);
        
        return ans;
    }
};