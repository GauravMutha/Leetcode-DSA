//Similar to 84.Largest rectangle histogram

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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m=matrix.size() , n=matrix[0].size() , res=0;
        vector<int>vec(n,0);
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++)
                matrix[i][j]=='1' ? vec[j]++ : vec[j]=0;
            
            int ithMax=largestRectangleArea(vec);
            res=max(res,ithMax);
        }
        
        return res;
    }
};