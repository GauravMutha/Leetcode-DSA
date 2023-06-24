class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0 , maxLen=0 , r=0 , l=0;
        unordered_map<char,int>m;
        for(r=0;r<s.size();r++){
            m[s[r]]++;
            if(m[s[r]]>1){
                len=r-l;
                maxLen=max(maxLen,len);
                while(m[s[r]]>1) m[s[l]]-- , l++;
            }
        }
        maxLen=max(r-l,maxLen);
        
        return maxLen;
    }
};