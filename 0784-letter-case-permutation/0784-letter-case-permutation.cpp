//Re//
class Solution {
private:
    vector<string>ans;
public:
    void helper(int pos,string &s){
        ans.push_back(s);
        if(pos>=s.size()){
            return;
        }
        for(int i=pos;i<s.size();i++){
            if(isdigit(s[i])) continue;
            s[i]=islower(s[i]) ? toupper(s[i]) :tolower(s[i]);
            helper(i+1,s);
            s[i]=islower(s[i]) ? toupper(s[i]) :tolower(s[i]);
        }
    }
    vector<string> letterCasePermutation(string s) {
        helper(0,s);
        return ans;
    }
};