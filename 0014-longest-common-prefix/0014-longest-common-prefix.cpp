//Without sorting
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ref=strs[0];
        int ans=strs[0].size();
        for(int i=0;i<strs.size();i++){
            int j=0;
            while(j<(ans,strs[i].size()) && strs[0][j]==strs[i][j]) j++;
            ans=min(ans,j);
        }
        return strs[0].substr(0,ans);
    }
};