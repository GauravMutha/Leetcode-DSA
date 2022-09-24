class Solution {
public:
    string truncateSentence(string s, int k) {
        string res;
        int wc=0;
        for(auto c:s){
            if(c==32)
                wc++;
            if(wc==k)
                break;
            res+=c;
        }
        
        return res;
    }
};