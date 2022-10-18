class Solution {
public:
    int atmost(vector<int>nums,int k){
        int count=0,j=0,i=0,res=0;
        for(j=0;j<nums.size();j++){
            if(nums[j]%2) count++;
            while(count>k){
                if(nums[i++]%2) count--;
            }
            res+=(j-i+1);
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (atmost(nums,k)-atmost(nums,k-1));
    }
};