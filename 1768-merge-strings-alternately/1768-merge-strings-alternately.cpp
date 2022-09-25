class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0,sz1=word1.size(),sz2=word2.size();
        string res(sz1+sz2,' ');
        
        while(i<sz1 || j<sz2){
            if(i<sz1)
                res[j+ i++]=word1[i];
            if(j<sz2)
                res[i + j++]=word2[j];
        }
        
        return res;
    }
};

//Single Pass --- Two Pointers + No temporary strings formed for res