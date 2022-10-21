class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>res;
        vector<int>m(26,0),pmap(26,0);
        for(auto c : p) pmap[c-'a']++;
        int k=p.size();
        for(int r=0;r<s.size();r++){
            m[s[r]-'a']++;
            if(r>=k){
                m[s[r-k]-'a']--;
            }
            if(m==pmap && r>=k-1) res.push_back(r-k+1);
        }
        return res;
    }
};

//using hash array instead of map