class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int>m;
        int val=0;
        for(auto c:s)
            m[c]++;
        val=m[s[0]];
        
        for(auto &[key,value]: m)
            if(value!=val) return false;
        
        return true;
    }
};