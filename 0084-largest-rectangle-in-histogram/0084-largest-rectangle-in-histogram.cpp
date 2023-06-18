class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<pair<int,int>>st;
        int n=nums.size(), currArea=0,maxArea=INT_MIN;
        vector<int>smallerToLeft(n,-1),smallerToRight(n,n);
        
        for(int i=n-1;i>=0;i--){
            while(st.size() && st.top().first>=nums[i]) st.pop();
            if(!st.empty()) smallerToRight[i]=st.top().second;
            st.push({nums[i],i});
        }
        while(st.size()) st.pop();
        for(int i=0;i<n;i++){
            while(st.size() && st.top().first>=nums[i]) st.pop();
            if(!st.empty()) smallerToLeft[i]=st.top().second;
            st.push({nums[i],i});
        }
        
        for(int i=0;i<n;i++){
            currArea=nums[i]*((smallerToRight[i]-smallerToLeft[i])-1);
            maxArea=max(currArea,maxArea);
        }
        return maxArea;
    }
};