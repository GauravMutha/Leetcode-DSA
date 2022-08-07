class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        //Optimizing for space usage by removing the need of prefix array
        vector<int>ans={};
        int total=nums[0];
        for(int i=1;i<nums.size();i++){
            total^=nums[i];
        }
        int maxxor=pow(2,maximumBit)-1;
        for(int j=nums.size()-1;j>=0;j--){
            ans.push_back(total^maxxor);
            total^=nums[j];
        }
        return ans;
    }
};