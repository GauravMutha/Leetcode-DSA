class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>m;
        vector<bool>given(256,false);
        int i=0;
        
        while(i<s.size()){
            if(m.count(t[i])==0){
                if(given[s[i]]) return false;
                given[s[i]]=true;
                m[t[i]]=s[i];
            }
            t[i]=m[t[i]] , i++;
        }
        return (t==s);
    }
};