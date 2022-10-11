class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
        unordered_map<char,char>m;
        bool flag=true;
        for(auto str : words){
            vector<bool>visited(26,false);
            flag=true;
            for(int i=0;i<str.size();i++){
                if((m.count(str[i]) && (m[str[i]]!=pattern[i])) ||
                   ((m.count(str[i])==0) && visited[pattern[i]-'a']) ){
                    flag=false;
                    break;
                }
                else{
                    m[str[i]]=pattern[i];
                    visited[pattern[i]-'a']=true;
                }
            }
            if(flag) res.push_back(str);
            m.clear();
        }
        return res;
    }
};

//Uses 1 map and one boolean array array insted of 2 maps