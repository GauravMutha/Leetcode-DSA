class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string res;
        for(auto str : words){
            res+=(str);
            if(res==s) return true;
            if(res.size()>s.size()) return false;
        }
        return false;
    }
};