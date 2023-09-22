class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int sz1=t.size(), sz2=s.size(),i=0,j=0;
        if(sz2>sz1) return false;
        
        for(i=0,j=0;i<sz1 && j<sz2;i++) if(t[i]==s[j]) j++;
        
        if(j>=sz2) return true;
        return false;
    }
};