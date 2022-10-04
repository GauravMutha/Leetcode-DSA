class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        unordered_map<char,int>m1,m2;
        vector<string>res;
        int l=0,r=1;
        for(auto c:words[0])
            m1[c]++;
        while(r<words.size()){
            for(auto c:words[r])
                m2[c]++;
            if(m1==m2){
                r++;
            }
            else {
                res.push_back(words[l]);
                m1=m2;
                l=r;
                r++;
            }
            m2.clear();
        }
        res.push_back(words[l]);
        return res;
    }
};