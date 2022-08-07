class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>ans={};
        vector<int>prexor(nums.size(),nums[0]);
        for(int i=1;i<nums.size();i++){
            prexor[i]=prexor[i-1]^nums[i];
        }
        int maxxor=pow(2,maximumBit)-1;
        for(int j=nums.size()-1;j>=0;j--){
            ans.push_back(prexor[j]^maxxor);
        }
        return ans;
    }
};