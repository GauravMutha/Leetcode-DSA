class Solution {
public:
    string reformat(string s) {
        string al="" ,di="";
        int i=0,a=0,d=0;
        bool flag;
        
        for(auto c:s)
            (isalpha(c)) ? al.push_back(c) : di.push_back(c);
        
        if(abs(int(al.size()-di.size())) > 1) return "";
        
        flag=al.size()>di.size();
        while(i<s.size()){
            (flag) ? s[i++]=al[a++] : s[i++]=di[d++];
            flag=!flag;
        }
        return s;
    }
};