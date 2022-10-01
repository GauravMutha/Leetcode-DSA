class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>m(26,0);
        if(s.size()!=t.size()) return false;
        
        for(int i=0;i<s.size();i++){
            m[s[i]-'a']++;
            m[t[i]-'a']--;
        }        
        return (count(begin(m),end(m),0) == m.size()) ;
    }
};