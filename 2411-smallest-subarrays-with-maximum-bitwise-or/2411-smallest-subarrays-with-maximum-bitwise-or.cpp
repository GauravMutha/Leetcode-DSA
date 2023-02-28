//Suffix array O(N)
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int>res(nums.size()), Indices(32);
        for(int i=nums.size()-1;i>=0;i--){
            int maxIndex=i;
            for(int j=0;j<32;j++){
                if(nums[i]&(1<<j)) Indices[j]=i;
                
                maxIndex=max(maxIndex,Indices[j]);
            }
            res[i]=maxIndex-i+1;
        }
        return res;
    }
};