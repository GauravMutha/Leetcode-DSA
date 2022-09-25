class Solution {
public:
    bool judgeCircle(string moves) {
        int y=0,x=0;
        if(moves.size()%2!=0) return false;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U') y++;
            
            else if (moves[i]=='D') y--;
            
            else if(moves[i]=='R') x++;
            
            else x--;
        }
        
        return x==0 && y==0;
    }
};