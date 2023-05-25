class Solution {
private:
    vector<vector<string>>res;
public:
        bool safeRow(int row, int col, vector < string > board, int n) {
      // check upper element
      int duprow = row;
      int dupcol = col;

      while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
    }
    void helper(int col,vector<string>& board,int n){
        if(col==n){
            res.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(safeRow(row,col,board,n)){
                board[row][col]='Q';
                helper(col+1,board,n);
                board[row][col]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector < string > board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
          board[i] = s;
        }
        helper(0,board,n);
        return res;
    }
};
