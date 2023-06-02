//Purely recursive - optimisation
class Solution {
private:
    //hashes
    int rHash[9][10] , cHash[9][10] , cube[3][3][10];
public:
    bool helper(int i,int j,vector<vector<char>>& board){
        if(i>=board.size()) return true;
        
        if(j>=board.size()) return helper(i+1,0,board);
        if(board[i][j]!='.') return helper(i,j+1,board);
        
        for(char num='1';num<='9';num++){
            
            if(check(num,i,j)==false) continue;
            
            rHash[i][num-'0']=1;
            cHash[j][num-'0']=1;
            cube[i/3][j/3][num-'0']=1;
            board[i][j]=num;
            
            if(helper(i,j+1 ,board)) return true;
            
            rHash[i][num-'0']=0;
            cHash[j][num-'0']=0;
            cube[i/3][j/3][num-'0']=0;
            board[i][j]='.';
        }

        return false;
    }
    bool check(char num ,int r,int c){
        if(rHash[r][num-'0']==1) return false;
        if(cHash[c][num-'0']==1) return false;
        if(cube[r/3][c/3][num-'0']==1) return false;
        
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        /*Initialising Hashes by putting 1 where
        there is a number (already filled) and
        0 otherwise*/
        memset(rHash, 0, sizeof(rHash));
        memset(cHash, 0, sizeof(cHash));
        memset(cube, 0, sizeof(cube));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]=='.') continue;
                rHash[i][board[i][j]-'0']=1,
                cHash[j][board[i][j]-'0']=1,
                cube[i/3][j/3][board[i][j]-'0']=1;
            }
        }
        
        helper(0,0,board);
    }
};