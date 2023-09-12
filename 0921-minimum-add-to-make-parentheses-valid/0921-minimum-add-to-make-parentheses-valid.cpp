class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,extraClosed=0;
        for(auto c : s){
            if(c=='(') open++;
            else (open)?open--:extraClosed++;
        }
        return open+extraClosed;
    }
};