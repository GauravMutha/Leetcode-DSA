class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res=0;
        for(auto j :jewels){
            for(auto s:stones){
                if(s==j)res++;
            }
        }
        
        return res;
    }
};