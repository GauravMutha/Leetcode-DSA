class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        int r=0,l=0;
        vector<int>m1(26,0),m2(26,0);
        for(auto c :s1)
            m1[c-'a']++;
        
        while((r-l+1)<=s1.size()) m2[s2[r++]-'a']++;
        r--;
        while(r<s2.size() && l<s2.size()){
            if(m1==m2) return true;
            r++;
            if(r<s2.size())m2[s2[r]-'a']++;
            m2[s2[l]-'a']--;
            l++;
        }
        return false;
    }
};