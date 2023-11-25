class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int total=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size(),dsb=0,dsf=0,presum=0,currsum=0;
        vector<int>res;
        
        for(int i=0;i<n;i++){
            
            currsum=nums[i]+presum;
            
            dsb=i*nums[i]-presum;
            dsf=total-currsum-(n-i-1)*nums[i];
            
            presum=currsum;
            res.push_back(dsf+dsb);
        }
        
        return res;
    }
};