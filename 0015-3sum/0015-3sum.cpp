class Solution {
private:
    int n=0;
    vector<vector<int>>res;
    unordered_map<int,int>m;
public:
    void twoSum(int start,vector<int>& nums,int target){
        
        for(int i=start;i<n-1;i++){
            int target2=target-nums[i];
            if(i>start && nums[i]==nums[i-1] ||
               m.find(target2)==m.end()||
               m[target2]<=i) 
                continue;
            
            
            res.push_back(vector<int>{-target,nums[i],target2});
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        n=nums.size();
        for(int i=0;i<n;i++) m[nums[i]]=i;
        
        int target=0;
        for(int i=0;i<n-2;i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            twoSum(i+1,nums,target-nums[i]);
        }
        
        return res;
    }
};