class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        if(k==nums.size()) return accumulate(nums.begin(),nums.end(),0);
        
        int n=nums.size() , l=0,r=0,res=INT_MIN,total=nums[0];
        vector<int>prefix(n,nums[0]);
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
            total+=nums[i];
        }
        for(int r=0;r<n;r++){
            if((r-l+1)<(n-k)) continue;
            int windowSum=prefix[r]-prefix[l]+nums[l];
            int extremeSum=total-windowSum;
            
            
            res=max(res,extremeSum);
            l++;
        }
        
        return res;
    }
};