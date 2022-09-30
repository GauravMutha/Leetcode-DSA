class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int>m(26,0);
        
        for(int i=0;i<word1.size() && i<word2.size() ;i++){
            m[word1[i]-'a']++;
            m[word2[i]-'a']--;
        }
        
        for(auto e : m)
            if(e>3 || e<-3) return false;
        
        return true;
    }
};