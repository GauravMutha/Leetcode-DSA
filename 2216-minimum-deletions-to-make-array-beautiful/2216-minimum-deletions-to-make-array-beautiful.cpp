class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int k=0;
        for(int i=0,j=0;j<nums.size();i++,j++){
            nums[i]=nums[j];
            if(j>0 && nums[j-k]==nums[j-1-k] && (j-k)%2) i-- , k++;
        }
        return k+(nums.size()-k)%2;
    }
};