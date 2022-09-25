class Solution {
public:
    char repeatedCharacter(string s) {
        int i=0,h=0;
        
        for(i=0;i<s.size();i++){
            if(h&(1<<(s[i]-97))) break;
            h|=1<<(s[i]-97);
        }
        
        return s[i];
    }
};