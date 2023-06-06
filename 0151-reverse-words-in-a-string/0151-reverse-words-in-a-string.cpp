//Slightly better code than previous to previous but still naive
class Solution {
public:
    string reverseWords(string s) {
        string str,res;
        for(int i=s.size()-1;i>=0;){
            if(s[i]==' '){
                while(i>=0 && s[i]==' ') i--;
                res+=str;
                if(res.size()>0) res.push_back(' ');
                str="";
             }
            else str=s[i--]+str;
        }
        res+=str;
        if(res.size()>0 && res.back()==' ') res.pop_back();
        return (res.size()==0)?s:res;
    }
};