class Solution {
public:
    bool check(string s, string str){
        for(int i=0;i<s.size();i+=str.size()){
            string curr=s.substr(i,str.size());
            if(curr!=str) return false;
        }
        return true;
    }
    bool repeatedSubstringPattern(string s) {
        string str;
        for(int i=0;i<s.size()/2;i++){
            str+=s[i];
            if(s.size()%str.length()) continue;
            bool x=check(s.substr(i+1),str);
            if(x) return true;
        }
        return false;
    }
};