class Solution {
public:
    int minimumMoves(string s) {
        int moves=0,i=0;
        
        while(i<s.size()){
            if(s[i]=='O') i++;
            else moves++,i+=3;
        }
        
        return moves;
    }
};