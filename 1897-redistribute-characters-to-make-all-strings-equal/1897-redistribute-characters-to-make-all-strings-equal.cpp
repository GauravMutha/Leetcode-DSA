class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int>hash(26,0);
        
        for(auto w:words)
            for(auto c:w)
                hash[c-'a']++;
        
        for(int i=0;i<26;i++)
            if(hash[i]%words.size()) return false;
        
        return true;
    }
};