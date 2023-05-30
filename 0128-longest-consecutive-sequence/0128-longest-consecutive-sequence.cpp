//Using set
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size() , maxLen=0, len=1;
        if(n==0) return n;
        
        unordered_set<int> st(begin(nums), end(nums));
        
        for(int i=0;i<n;i++){
            //ignoring those who are not starting any sequence
            if(st.count(nums[i]-1)) continue;
            
            int len=1;
            while(st.count(nums[i]+len)) len++;
            maxLen=max(maxLen,len);
        }
        
        return maxLen;
    }
};