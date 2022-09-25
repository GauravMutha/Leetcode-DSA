class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        string res;
        
        while((i<word1.size()) && (i<word2.size()))
            res+= string() + word1[i] + word2[i++];
        
        return res+ word1.substr(i) + word2.substr(i);
    }
};

//Less Cluttery code which iterates i , j altogether 
//and also using substr method to merge remaining characters,if any.