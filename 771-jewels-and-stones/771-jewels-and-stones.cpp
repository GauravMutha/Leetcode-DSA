class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res=0;
        
        vector<int>upper(26,0);
        vector<int>lower(26,0);
        
        for(auto c:jewels)
            (c<=90)?upper[c-65]++:lower[c-97]++;
        
        for(auto c:stones){
            if(c<=90){
                if(upper[c-65])res++;
            }
            else{
                if(lower[c-97])res++;
            }
        }
        return res;
    }
};