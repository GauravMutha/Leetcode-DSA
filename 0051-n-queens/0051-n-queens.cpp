class Solution {
private:
    vector<vector<string>>res;
public:
    void helper(int col,vector<string>& board,int n,vector<int>&left,vector<int>&upDia,vector<int>&downDia){
        if(col==n){
            res.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(left[row]==0 && upDia[row+col]==0 && downDia[n-1+col-row]==0){
                
                left[row]=1, upDia[row+col]=1,downDia[n-1+col-row]=1;
                board[row][col]='Q';
            
                helper(col+1,board,n,left,upDia,downDia);
            
                board[row][col]='.';
                left[row]=0, upDia[row+col]=0,downDia[n-1+col-row]=0;
            }
        }
        
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<int>left(n,0), upDia(2*n-1,0),downDia(2*n-1,0);
        helper(0,board,n,left,upDia,downDia);
        return res;
    }
};