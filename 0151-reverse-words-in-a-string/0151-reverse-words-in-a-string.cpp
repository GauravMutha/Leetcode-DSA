//Slightly better code than previous but still naive
class Solution {
public:
    string reverseWords(string s) {
        string str,res;
        int i=s.size()-1;
        // making sure that we directly start from a character
        while(i>=0 && s[i]==' ') i--;
        for(;i>=0;i--){
            if(s[i]==' '){
                while(i>=0 && s[i]==' ') i--;
                if(i<0) break;
                res+=str;
                res.push_back(' ');
                str="";
             }
            str=s[i]+str;
        }
        res+=str;
        return (res.size()==0)?s:res;
    }
};