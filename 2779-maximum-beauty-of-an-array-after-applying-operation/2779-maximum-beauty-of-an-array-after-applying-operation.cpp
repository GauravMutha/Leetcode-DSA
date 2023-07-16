//sliding window
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        
        int ans=0 , f=0,b=0 , n=nums.size();
        sort(nums.begin(),nums.end());
        
        for(f=0;f<n;f++){
            if((nums[f]-nums[b])>2*k) b++;
        }
        
        return f-b;
    }
};