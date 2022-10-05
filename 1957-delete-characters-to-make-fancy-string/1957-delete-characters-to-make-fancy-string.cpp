class Solution {
public:
    string makeFancyString(string s) {
        int count=1;
        string res;
        res.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            (s[i]==s[i-1]) ? count++ : count=1;
            if(count<3) res.push_back(s[i]);
        }
        return res;
    }
};