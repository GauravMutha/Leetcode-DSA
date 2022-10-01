class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>hash(26,0),balloon(26,0);
        string b="balloon";
        int res=INT_MAX;
        for(auto c:text)
            hash[c-'a']++;
        for (auto c: b)
            balloon[c-'a']++;
        for(auto c : b)
            res=min(res, hash[c-'a']/balloon[c-'a']);
        
        return res;
        
    }
};