class Solution {
public:
    string reverseWords(string s) {
        int l=0;
        for(int r=0;r<s.size();r++){
            if(s[r]!=32)continue;
            reverse(s.begin()+l,s.begin()+r);
            l=r+1;
        }
        reverse(s.begin()+l,s.end());
        return s;
    }
};