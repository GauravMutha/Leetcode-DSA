class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>hash(26,0);
        int sum=0;
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
            hash[t[i]-'a']--;
        }
        
        for(int i=0;i<hash.size();i++)
            if(hash[i]<0) sum+=(hash[i]);
        
        return abs(sum);
    }
};