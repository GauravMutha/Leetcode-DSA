//O(n^2*(log(n)))
//better than O(n^3)
class Solution {
private:
    vector<vector<int>>res;
    unordered_map<int,int>m;
public:
    void twoSum(vector<int>& nums, int target,int i) {
        
        for(int j=i+1;j<nums.size();j++){
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int require=target-nums[j];
            if(m.find(require)!=m.end() && m[require]>j)
                res.push_back({-target,nums[j],require});
        }
        
        return;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++) m[nums[i]]=i;
        
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && (nums[i]==nums[i-1]) ) continue;
            if(nums[i]>0) return res;
            
            int target=-nums[i];
            twoSum(nums,target,i);
        }
        
        return res;
    }
};