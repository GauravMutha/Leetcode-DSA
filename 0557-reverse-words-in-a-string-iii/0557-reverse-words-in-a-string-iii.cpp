class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        int prevSpace=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' ') continue;
            reverse(s.begin()+prevSpace+1,s.begin()+i);
            prevSpace=i;
        }
        s.pop_back();
        return s;
    }
};