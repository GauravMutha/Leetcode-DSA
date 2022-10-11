class Solution {
public:
    string normalise(string str){
        vector<char>mp(26);
        char alphabet='a';
        for(auto c :str)
            if(!mp[c-'a']) mp[c-'a']=alphabet++;
        for(auto &c : str)
            c=mp[c-'a'];
        
        return str;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
        pattern=normalise(pattern);
        for(auto str : words)
            if(normalise(str)==pattern) res.push_back(str);
        return res;
    }
};
//Normalisation method
//Uses 1 hash array of size 26