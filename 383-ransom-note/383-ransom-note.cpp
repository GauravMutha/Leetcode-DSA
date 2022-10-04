class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int r=ransomNote.size(),m=magazine.size();
        vector<int>hash(26,0);
        if(m<r) return false;
        for(int i=0;i<m;i++)
            hash[magazine[i]-'a']++;
        
        for(int i=0;i<r;i++){
            if(hash[ransomNote[i]-'a']==0) return false;
            hash[ransomNote[i]-'a']--;
        }
        
        return true;
    }
};