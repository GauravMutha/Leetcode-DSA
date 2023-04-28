//Similar to 1219.Path with Maximum Gold
class Solution {
private:
    int m,n,found=0;
public:
    bool helper(int i,int j,string &ds,vector<vector<char>>&mat,string &target,vector<vector<bool>>& vis){
        
        if(ds.size()==target.size()) return true;
        
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j]) return false;
        if(mat[i][j]!=target[ds.size()]) return false;
        
        ds.push_back(mat[i][j]);
        vis[i][j]=true;
        
        if(helper(i-1,j,ds,mat,target,vis)) return true; //top
        if(helper(i+1,j,ds,mat,target,vis)) return true; //bottom
        if(helper(i,j+1,ds,mat,target,vis)) return true; //right
        if(helper(i,j-1,ds,mat,target,vis)) return true; //left
        
        ds.pop_back();
        vis[i][j]=false;
        
        return false;
    }
    bool exist(vector<vector<char>>& mat, string word) {
        m=mat.size(),n=mat[0].size();
        string ds="";
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(helper(i,j,ds,mat,word,vis)) return true;
            }
        }
        return false;
    }
};