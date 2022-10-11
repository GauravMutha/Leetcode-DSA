class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
        unordered_map<char,char>ms,mp;
        bool flag=true;
        for(auto str : words){
            flag=true;
            for(int i=0;i<str.size();i++){
                if(ms.count(str[i]) && ms[str[i]]!=pattern[i] ||
                  mp.count(pattern[i]) && mp[pattern[i]]!=str[i]){
                    flag=false;
                    break;
                }
                ms[str[i]]=pattern[i];
                mp[pattern[i]]=str[i];
            }
            if(flag) res.push_back(str);
            ms.clear() , mp.clear();
        }
        return res;
    }
};

//Former solution was mapping each char of two string to same integer value
//this solution does the mapping too but char to char.