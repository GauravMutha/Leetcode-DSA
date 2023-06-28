class Solution {
public:
    int m,n,srcColor;
    void helper(int i,int j,vector<vector<int>>& image,vector<vector<bool>>vis,int color){
        
        vis[i][j]=true;
        image[i][j]=color;
        
        if(j+1<n && vis[i][j+1]==false && image[i][j+1]==srcColor)
            helper(i,j+1,image,vis,color);
        
        if(j-1>=0 && vis[i][j-1]==false && image[i][j-1]==srcColor)
            helper(i,j-1,image,vis,color);
        
        if(i+1<m && vis[i+1][j]==false && image[i+1][j]==srcColor)
            helper(i+1,j,image,vis,color);
        
        if(i-1>=0 && vis[i-1][j]==false && image[i-1][j]==srcColor)
            helper(i-1,j,image,vis,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m=image.size() , n=image[0].size(), srcColor=image[sr][sc];
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        
       helper(sr,sc,image,vis,color);
        
        return image;
    }
};