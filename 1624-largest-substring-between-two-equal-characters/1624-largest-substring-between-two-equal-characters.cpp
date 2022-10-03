class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int>start(26,-1);
        vector<int>end(26,-1);
        int ans=-1;
        for(int i=0,k=s.size()-i-1;k>=0;i++,k--){
            start[s[k]-'a']=k;
            end[s[i]-'a']=i;
        }
        for(int i=0;i<26;i++)
            if(start[i]!=end[i]) ans=max(ans,end[i]-start[i]-1);
        
        return ans;
    }
};