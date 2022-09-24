class Solution {
public:
    string truncateSentence(string s, int k) {
        string res;
        int wc=1;
        wc=count(s.begin(),s.end(),' ');
        
        if(k==(wc+1)) return s;
        
        wc=0;
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