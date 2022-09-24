class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int inConsistent=0,hash=0,n=words.size();
        
        for(auto c:allowed)
            hash|=(1<<(c-'a'));
        
        for(auto w:words)
            for(auto c:w)
                if(!(hash&(1<<(c-'a')))){
                    n--;
                    break;
                }
        
        return n;
    }
};