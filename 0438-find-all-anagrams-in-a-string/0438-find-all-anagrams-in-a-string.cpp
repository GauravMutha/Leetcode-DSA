class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>res;
        unordered_map<char,int>m,pmap;
        for(auto c : p) pmap[c]++;
        int k=p.size();
        for(int r=0;r<s.size();r++){
            m[s[r]]++;
            if(r>=k){
                m[s[r-k]]--;
                if(m[s[r-k]]==0) m.erase(s[r-k]);
            }
            if(m==pmap) res.push_back(r-k+1);
        }
        return res;
    }
};

//using hash table