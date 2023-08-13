class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,r=heights.size()-1 ,res=0;
        while(l<r){
            int w=r-l;
            int h=min(heights[l],heights[r]);
            int area=w*h;
            
            res=max(res,area);
            
            if(heights[l]<heights[r]) l++;
            else r--;
            
        }
        
        return res;
    }
};