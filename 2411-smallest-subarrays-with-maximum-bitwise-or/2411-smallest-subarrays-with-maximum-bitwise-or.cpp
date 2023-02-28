//Binary search
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int>res(nums.size());
        
        unordered_map<int,vector<int>>setBitIndices;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<32;j++){
                if(nums[i]&(1<<j)) setBitIndices[j].push_back(i);
            }
        }
        
        for(int i=0;i<nums.size();i++){
            int maxIndex=i;
            for(int j=0;j<32;j++){
                auto it=lower_bound(begin(setBitIndices[j]),end(setBitIndices[j]),i);
                if(it!=setBitIndices[j].end()) maxIndex=max(maxIndex,*it);
            }
            res[i]=maxIndex-i+1;
        }
        
        return res;
    }
};