class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int>hash(26,0);
        int count=0;
        for(int i=0;i<s1.size();i++)
            hash[s1[i]-'a']++ , hash[s2[i]-'a']--;
        for(int i=0;i<26;i++)
            if(hash[i]) return false; 
        
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]) count++;
            if(count>2) return false;
        }
        
        return true;
    }
};