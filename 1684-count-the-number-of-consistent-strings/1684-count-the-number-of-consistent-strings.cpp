class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int inConsistent=0;
        
        vector<int>vec(26,0);
        for(auto c:allowed)
            vec[c-'a']++;
        
        for(auto w:words)
            for(auto c:w)
                if(!vec[c-'a']){
                    inConsistent++;
                    break;
                }
        
        return (words.size()-inConsistent);
    }
};