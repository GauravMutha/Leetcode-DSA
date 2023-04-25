class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int lAcc=0,rAcc=0,n=nums.size();
        vector<int>lSum(n),rSum(n),ans(n);
        for(int i=0,j=nums.size()-1;i<nums.size() && j>=0;i++,j--){
            lAcc+=(i>0)?nums[i-1]:0;
            rAcc+=(j<nums.size()-1)?nums[j+1]:0;
            lSum[i]=lAcc , rSum[j]=rAcc;
        }
        for(int i=0;i<nums.size();i++)
            ans[i]=abs(lSum[i]-rSum[i]);
        return ans;
    }
};