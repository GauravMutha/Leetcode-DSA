class Solution {
public:
    bool isvowel(char c){
        return (c=='a' || c=='e' || c=='o' || c=='i' || c=='u');
    }
    int maxVowels(string s, int k) {
        int r=0,l=0,maxi=0,vow=0;
        
        while(k--) vow+=isvowel(s[r++]);
        r--;
        maxi=max(vow,maxi);
        if(maxi==k) return maxi;
        
        while(r<s.size()){
            r++;
            if(r>=s.size()) break;
            vow+=isvowel(s[r]);
            vow-=isvowel(s[l]);
            l++;
            
            maxi=max(vow,maxi);
            if(maxi==k) return maxi;
        }
        return maxi;
    }
};