class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res=0;
        
        vector<int>alph(52,0);
        
        for(auto c:jewels)
            (c<=90)?alph[c-65]++:alph[c-71]++;
        
        for(auto c:stones){
            if(c<=90){
                if(alph[c-65])res++;
            }
            else{
                if(alph[c-71])res++;
            }
        }
        return res;
    }
};