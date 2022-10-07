class Solution {
public:
    char change(string& s , int i){
        char c;
        for(c='a';c<'z';c++){
            if(c!=s[i-1] && c!=s[i+1]){
                break;
            }
        }
        return c;
    }
    string modifyString(string s) {
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])) continue;
            
            if(i+1==s.size() || s[i+1]=='?')
                s[i]=(i-1>=0) ? change(s,i) : 'a';
            else if(isalpha(s[i+1])){
                if(i-1>=0){
                    s[i]=change(s,i);
                }
                else 
                    s[i]=(s[i+1]=='z') ? 'a' : s[i+1]+1;
            }
        }
        return s;
    }
};