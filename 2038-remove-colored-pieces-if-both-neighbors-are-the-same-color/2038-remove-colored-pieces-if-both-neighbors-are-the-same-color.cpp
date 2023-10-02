class Solution {
public:
    bool winnerOfGame(string s) {
        int n=s.size(),countA=0, countB=0;//counts of sandwiched A and B
        if(n<3) return false; //alice lost
        for(int i=1;i<n-1;i++){
            if(s[i]!=s[i+1] || s[i]!=s[i-1]) continue;
            else countA+=(s[i]=='A') ,countB+=(s[i]=='B');
        } 
        
        return (countA>countB);
    }
};