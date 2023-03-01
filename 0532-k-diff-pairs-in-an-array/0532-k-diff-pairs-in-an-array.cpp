//Sort + Two pointers
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int i=0,j=1,n=nums.size(),count=0;
        while(i<n && j<n){
            if((nums[j]-nums[i])==k){
                count++;
                i++;
                j++;
                while(j<n && nums[j-1]==nums[j]) j++;
            }
            else if((nums[j]-nums[i])>k){
                i++;
                if(j==i) j++;
            }
            else j++;
        }
        
        return count;
    }
};