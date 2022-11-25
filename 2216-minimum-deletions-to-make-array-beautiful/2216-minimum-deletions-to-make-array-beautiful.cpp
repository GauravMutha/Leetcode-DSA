class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int k=0;
        stack<pair<int,int>>st;
        for(int i=0;i<nums.size();i++){
            if(!st.empty() && st.top().first==nums[i] && ((st.top().second)%2)==0)
                k++;
            else st.push({nums[i],i-k});
        }
        return k+ (st.size()%2);
    }
};