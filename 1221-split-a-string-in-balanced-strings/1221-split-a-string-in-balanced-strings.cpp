class Solution {
public:
    int balancedStringSplit(string s) {
        int count=0,res=0;
        for(auto c:s){
            (c=='R')?count--:count++;
            if(!count)res++;
        }
        return res;
    }
};