class Solution {
public:
    string truncateSentence(string s, int k) {
         for(int i=0;i<s.size();i++){
             if(s[i]==' ') k--;
             if(!k) return s.substr(0,i);
         }
        return s;
    }
};