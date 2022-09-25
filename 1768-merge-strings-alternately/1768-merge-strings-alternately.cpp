class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        string res;
        
        while((i<word1.size()) && (j<word2.size()))
            res+= string() + word1[i++] + word2[j++];
        
        for(;i<word1.size();i++)
            res.push_back(word1[i]);
        for(;j<word2.size();j++)
            res.push_back(word2[j]);
        
        return res;
    }
};

//Less Cluttery code which iterates i , j altogether 