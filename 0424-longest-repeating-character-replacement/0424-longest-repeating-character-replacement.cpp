class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=0,maxFreq=0,l=0,r=0;
        vector<int>hash(26,0);
        for(r=0;r<s.size();r++){
            hash[s[r]-'A']++;
            maxFreq=max(maxFreq,hash[s[r]-'A']);
            
            if(r-l+1 -maxFreq>k){
                res=max(res,(r-1)-l+1);
                hash[s[l]-'A']--;
                l++;
            }
        }
        return max(res,(r-1)-l+1);
    }
};

//* It keeps the maxFrequency unchanged even when left pointer is shifted