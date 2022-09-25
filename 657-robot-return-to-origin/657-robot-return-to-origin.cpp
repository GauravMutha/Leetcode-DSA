class Solution {
public:
    bool judgeCircle(string moves) {
        int y=0,x=0;
        
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U') y++;
            
            else if (moves[i]=='D') y--;
            
            else if(moves[i]=='R') x++;
            
            else x--;
        }
        
        return !( abs(x) | abs(y) );
    }
};