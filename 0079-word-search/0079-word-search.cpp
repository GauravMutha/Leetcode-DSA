//Similar to 1219.Path with Maximum Gold
//More concise + Without using  visited boolean array and a string ds
class Solution {
private:
    int m,n,found=0;
public:
    bool helper(int i,int j,int count,vector<vector<char>>&mat,string &target){
        
        if(count==target.size()) return true;
        
        if(i<0 || j<0 || i>=m || j>=n || mat[i][j]=='*') return false;
        if(mat[i][j]!=target[count]) return false;
        char letter=mat[i][j];
        count++;
        mat[i][j]='*'; //way of marking taken character in matrix
        
        if(helper(i-1,j,count,mat,target)||  
            helper(i+1,j,count,mat,target)||  
            helper(i,j+1,count,mat,target)|| 
            helper(i,j-1,count,mat,target)) return true;
        
        count--;
        mat[i][j]=letter; //way of unmarking a character and make it available for use
        
        return false;
    }
    bool exist(vector<vector<char>>& mat, string word) {
        m=mat.size(),n=mat[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(helper(i,j,0,mat,word)) return true;
            }
        }
        return false;
    }
};