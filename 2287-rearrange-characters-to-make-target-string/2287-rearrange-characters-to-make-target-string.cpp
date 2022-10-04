class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int>ms,mt;
        int ans=INT_MAX;
        for(auto c:s)
            ms[c]++;
        for(auto c:target)
            mt[c]++;
        
        for(auto &[key,value]:mt){
            ms[key]/=value;
            ans=min(ms[key],ans);
        }
        return ans;
    }
};