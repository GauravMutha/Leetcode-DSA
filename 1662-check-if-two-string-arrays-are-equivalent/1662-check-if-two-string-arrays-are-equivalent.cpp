class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1,s2;
        int i=0,j=0;
        while(i<word1.size() || j<word2.size()){
            if(i<word1.size()) s1+=word1[i];
            if(j<word2.size()) s2+=word2[j];
            
            i++,j++;
        }
        
        return (s1==s2);
    }
};