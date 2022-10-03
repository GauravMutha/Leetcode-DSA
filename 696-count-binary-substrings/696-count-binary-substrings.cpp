class Solution {
public:
    int countBinarySubstrings(string s) {
        int prevcount=0, currcount=1,ans=0;
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                ans+=min(prevcount,currcount);
                prevcount=currcount;
                currcount=1;
                continue;
            }
                currcount++;
        }
        ans+=min(currcount,prevcount);
        return ans;
    }
};