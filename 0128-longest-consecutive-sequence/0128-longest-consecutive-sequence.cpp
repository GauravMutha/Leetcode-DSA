//Sorting
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size() , maxLen=0, len=1;
        if(n==0) return n;
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if((nums[i]+1)==nums[i+1]) 
                len++;
            else if(nums[i]==nums[i+1]) continue;
            else{ 
                maxLen=max(len,maxLen);
                len=1;
            }
        }
        maxLen=max(len,maxLen);
        
        return maxLen;
    }
};