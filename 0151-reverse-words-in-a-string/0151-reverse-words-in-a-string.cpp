//Naive code
class Solution {
public:
    string reverseWords(string s) {
        string str,res;
        int i=s.size()-1;
        while(i>=0 && s[i]==' ') i--;
        for(;i>=0;i--){
            if(s[i]==' '){
                while(i>=0 && s[i]==' ') i--;
                res+=str;
                res.push_back(' ');
                str="";
             }
            if(i>=0)str=s[i]+str;
        }
        if(str.size()>0){
            res+=str;
        }
        if(res.back()==' ') res.pop_back();
        return (res.size()==0)?s:res;
    }
};