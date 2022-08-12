class Solution {
public:

vector<string> letterCasePermutation(string s){
    vector<string>x;
    backtrack(s,0,x);
    return x;
}

void backtrack(string &s,int i,vector<string>&ans){
    if(i==s.size()){
        ans.push_back(s);
        return;
    }
    char c=s[i];
    s[i]=(isupper(c))?tolower(c):toupper(c);
    backtrack(s,i+1,ans);
    if(isalpha(c)){
        s[i]=c;
        backtrack(s,i+1,ans);
    }
}
};