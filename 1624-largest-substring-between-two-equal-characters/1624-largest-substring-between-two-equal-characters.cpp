class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int>start(26);
        int ans=-1;
        for(int i=0;i<s.size();i++){
            if(start[s[i] - 'a']!=0) ans=max(ans,i-start[s[i]-'a']);
            else start[s[i]-'a']=i+1;
        }
        
        return ans;
    }
};