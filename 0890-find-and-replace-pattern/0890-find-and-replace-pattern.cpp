class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
        unordered_map<char,int>m1,m2;
        bool flag=true;
        for(auto str : words){
            flag=true;
            for(int i=0;i<str.size();i++){
                if(m1[str[i]]!=m2[pattern[i]]) {
                    flag=false;
                    break;
                }
                m1[str[i]]=m2[pattern[i]]=i+1;
            }
            if(flag) res.push_back(str);
            m1.clear() , m2.clear();
        }
        return res;
    }
};