class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack <pair<int,int>> st;
        vector<int> prefix(nums.size(), INT_MAX);

        int mini = INT_MAX;

        for(int i = 0; i<nums.size(); i++){
            prefix[i] = mini;
            mini = min(mini, nums[i]);    
        }
        
        for(int i = 0; i<nums.size(); i++){
            if(st.empty()) st.push({nums[i],i});
            else{
                while(!st.empty() and nums[i]>=st.top().first) st.pop();

                if(!st.empty() and prefix[st.top().second]<nums[i]) return true;
                
                st.push({nums[i],i});
            }
        }
        return false;
    }
};