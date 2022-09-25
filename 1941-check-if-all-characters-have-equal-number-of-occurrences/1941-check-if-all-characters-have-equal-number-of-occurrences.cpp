class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int>freq(26,0);
        int val=0;
        for(auto c : s)
            freq[c-'a']++;
        
        val=freq[s[0]-'a'];
        
        for(int i=0;i<26;i++)
            if(freq[i] && val!=freq[i]) return false;

        
        return true;
    }
};