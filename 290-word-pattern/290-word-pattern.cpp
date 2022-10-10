class Solution {
public:
    bool wordPattern(string p, string s) {
        int i=0,j=0;
        string res="";
        unordered_map<char,int>m1;
        unordered_map<string,int>m2;

        for(;i<p.size() && j<s.size();i++,j++){
            while(s[j]!=' ' && j<s.size())
                res+=s[j++];
            if((m1.count(p[i])^m2.count(res)) || (m1.count(p[i]) && m2.count(res) && (m1[p[i]]!=m2[res])))
                return false;
            m1[p[i]]=m2[res]=i+1;
            res="";
        }
        return (i>=p.size() && j>=s.size()) ? true : false;
    }
};