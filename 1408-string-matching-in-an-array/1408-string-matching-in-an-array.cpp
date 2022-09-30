class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>res;
        for(int i=0;i<words.size();i++)
            for(int j=0;j<words.size();j++)
                if(words[j].find(words[i])!=string::npos && words[i]!=words[j])
                    {res.push_back(words[i]); break;}
        
        return res;
    }
};