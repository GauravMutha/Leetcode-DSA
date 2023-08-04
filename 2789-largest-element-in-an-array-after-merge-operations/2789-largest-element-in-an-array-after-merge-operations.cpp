class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        
        long long adj=nums.back();
        long long res=adj;
        
        for(int i=nums.size()-2;i>=0;i--){
            long long temp=(adj>=nums[i]) ? adj : 0;
            adj=temp+nums[i];
            
            res=max(res,max((long long)nums[i],adj));
        }
        
        return res;
    }
};