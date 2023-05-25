//Time Complexity Optimised
class Solution {
private:
    vector<vector<string>>res;
public:
    void helper(int col,vector<string>& board,int n,vector<int>&leftCheck,vector<int>&upDiaCheck,vector<int>&downDiaCheck){
        if(col==n){
            res.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(leftCheck[row]==0 && upDiaCheck[n - 1 + col - row]==0 && downDiaCheck[row+col]==0){
                board[row][col]='Q';
                leftCheck[row]=1;
                upDiaCheck[n - 1 + col - row]=1;
                downDiaCheck[row+col]=1;
                
                helper(col+1,board,n,leftCheck,upDiaCheck,downDiaCheck);
                
                board[row][col]='.';
                leftCheck[row]=0;
                upDiaCheck[n - 1 + col - row]=0;
                downDiaCheck[row+col]=0;
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector < string > board(n,string(n,'.'));
        vector<int>leftCheck(n,0),upDiaCheck(2*n-1,0),downDiaCheck(2*n-1,0);
        helper(0,board,n,leftCheck,upDiaCheck,downDiaCheck);
        return res;
    }
};
