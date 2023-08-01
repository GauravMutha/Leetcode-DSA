//Revision of second approach
class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        
        stack<int>st;
        int n=nums.size() , maxArea=-1;
        
        for(int i=0;i<=n;i++){
            while(st.size() && ((i==n)||(nums[st.top()]>=nums[i]))){
                int height=nums[st.top()];
                st.pop();
                int width=(st.empty())? i: (i-st.top()-1);
                
                maxArea=max(maxArea,height*width);
            }
            st.push(i);
        }
        
        return maxArea;
    }
};