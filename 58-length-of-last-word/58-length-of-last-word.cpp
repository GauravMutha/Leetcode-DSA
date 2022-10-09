class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.size()-1 , l=0;
        while(!isalpha(s[i])) i--;
        l=i;
        while(i-1>=0 && s[i-1]!=' ') i--;
        
        return l-i+1;
    }
};