class Solution {
public:
    int balancedStringSplit(string s) {
        int countR=0,countL=0,res=0;
        for(auto c:s){
            (c=='R')?countR++:countL++;
            if(countL==countR)res++;
        }
        return res;
    }
};