class Solution {
public:
    int minDeletion(vector<int>& nums) {
        stack<pair<int,int>>st;
        for(int i=0;i<nums.size();i++){
            if(!st.empty() && st.top().first==nums[i] && ((st.top().second)%2)==0)
                continue;
            int x=(st.empty()) ? 0 : st.top().second+1;
            st.push({nums[i],x});
        }
        return nums.size()-st.size()+(st.size()%2);
    }
};