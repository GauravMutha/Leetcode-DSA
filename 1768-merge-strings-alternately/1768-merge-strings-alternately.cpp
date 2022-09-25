class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,sz1=word1.size(),sz2=word2.size();
        string res;
        
        while(i<max(sz1,sz2)){
            if(i<sz1)
                res+=word1[i];
            if(i<sz2)
                res+=word2[i];
            i++;
        }
        
        return res;
    }
};

//Single Pass --- One Pointers + No temporary strings formed for res