//Iterative+Recursive
class Solution {
public:
    bool helper(int row,int col,vector<vector<char>>& board){

        for(int i=row;i<board.size();i++,col=0){
            for(int j=col;j<board.size();j++){
                if(board[i][j]!='.') continue;
                for(char num='1';num<='9';num++){
                    if(check(num,i,j,board)==false) continue;
                    board[i][j]=num; 
                    if(helper(i,j+1 ,board)) return true;  
                    board[i][j]='.';
                }
                
                return false;
            }
        }
        cout<<"Hello";
        return true;
    }
    bool check(char num ,int r,int c, vector<vector<char>>board){
        int r2=(r/3) *3;     
        int c2=(c/3) *3;
        for(int i=0;i<board.size();i++){
            if(board[r][i]==num) return false;
            if(board[i][c]==num) return false;
            if(board[r2+(i/3)][c2+(i%3)]==num) return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(0,0,board);
    }
};