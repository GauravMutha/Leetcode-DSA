class Solution {
private:
    vector<vector<string>>res;
public:
    bool safe(int row, int col, vector<string>& board, int n){
        int dupRow=row, dupCol=col;
        
        while(dupCol>=0) if(board[dupRow][dupCol--]=='Q') return false;
        dupCol=col;
        while(dupCol>=0 && dupRow>=0) 
            if(board[dupRow--][dupCol--]=='Q') return false;
        dupCol=col, dupRow=row;
        while(dupRow<n && dupCol>=0)
            if(board[dupRow++][dupCol--]=='Q') return false;
        
        return true;
    }
    void helper(int col,vector<string>& board,int n){
        if(col==n){
            res.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(safe(row,col,board,n)) {
                board[row][col]='Q';
                helper(col+1,board,n);
                board[row][col]='.';
            }
        }
        
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        helper(0,board,n);
        return res;
    }
};