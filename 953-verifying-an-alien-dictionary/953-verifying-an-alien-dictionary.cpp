class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,char >m;
        for(int i=0;i<order.size();i++)
            m[order[i]]=i+'a';
        for(auto &w : words)
            for(auto &c:w)
                c=m[c];
        return is_sorted(begin(words),end(words));
    }
};

//TC-->O(N*S)