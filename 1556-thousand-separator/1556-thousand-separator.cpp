class Solution {
public:
    string thousandSeparator(int n) {
        string s=to_string(n),res;
        if(s.size()<4) return s;
        for(int i=0;i<s.size();i++){
            if(i>0 && ((s.size()-i)%3==0)) res+=".";
            res+=s[i];
        }
        return res;
    }
};