class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int>m(26,0);
        
        for(auto c : word1)
            m[c-'a']++;
        for(auto c : word2)
            m[c-'a']--;
        for(auto e : m)
            if(e>3 || e<-3) return false;
        
        return true;
    }
};