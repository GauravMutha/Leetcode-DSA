//DYNAMIC GENERATION using bit manipulation (on the fly)
class CombinationIterator {
private:
    int mask=0,targetSz=0;
    string s;
public:
    CombinationIterator(string characters, int combinationLength) {
        s=characters;
        mask=pow(2,characters.size())-1;
        targetSz=combinationLength;
    }
    
    string next() {
        while(mask && __builtin_popcount(mask)!=targetSz) mask--;
        string ans;
        for(int i=0;i<s.size();i++){
            if(mask&(1<<(s.size()-i-1)))
                ans.push_back(s[i]);
        }
        mask--;
        return ans;
    }
    
    bool hasNext() {
        while(mask && __builtin_popcount(mask)!=targetSz) mask--;
        if(!mask) return false;
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */