class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0,k=0;
        string res;
        
        for(i=0,j=0; (i<word1.size()) && (j<word2.size());){
            if(k%2==0){
                res.push_back(word1[i]);
                i++,k++;
            }
            else{
                res.push_back(word2[j]);
                k++,j++;
            }
        }
        
        for(;i<word1.size();i++)
            res.push_back(word1[i]);
        for(;j<word2.size();j++)
            res.push_back(word2[j]);
        
        return res;
    }
};