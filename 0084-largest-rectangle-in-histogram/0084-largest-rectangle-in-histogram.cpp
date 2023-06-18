class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<int>st;
        int n=nums.size(),height=0,width=0,maxArea=-1;
        
        for(int i=0;i<=n;i++){
            while(!st.empty() && ((i==n)||(nums[st.top()]>=nums[i])) ){
                height=nums[st.top()];
                st.pop();
                if(st.empty()) width=i; //in this case we cannot get the left smaller
                else width=i-st.top()-1;
                
                maxArea=max(maxArea,height*width);
            }
            st.push(i);
        }
        
        return maxArea;
    }
};