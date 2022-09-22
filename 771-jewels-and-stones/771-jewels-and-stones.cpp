class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res=0;
        unordered_set<char>uset(jewels.begin(),jewels.end());
        
        for(auto c:stones){
            if(uset.count(c))res++;
        }
        
        return res;
    }
};