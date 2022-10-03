class Solution {
public:
    int countBinarySubstrings(string s) {
        int count=1,res=0;
        vector<int>groups;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]) count++;
            else{
                groups.push_back(count);
                count=1;
            }
        }
        groups.push_back(count);
        
        for(int i=1;i<groups.size();i++)
            res+=min(groups[i],groups[i-1]);
        
        return res;
    }
};