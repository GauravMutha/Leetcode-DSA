class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0,count=0;
        
        for(int i=0;i<32;i++){
            count=0;
            int mask=1<<i;
            for(int j=0;j<nums.size();j++){
                if(nums[j]&mask)count++;
            }
            if(count%3)res|=mask;
        }
        return res;
    }
};
//TC--->O(32*n)~O(n)
//SC--->O(1)