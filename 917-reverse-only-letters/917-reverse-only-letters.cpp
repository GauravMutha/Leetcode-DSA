class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l=0,r=s.size()-1;
        while(l<r){
            while((l<s.size()) &&(!isalpha(s[l])) ) l++;
            while((r>=0) &&(!isalpha(s[r])) ) r--;
            
            if(l>=r) return s;
            swap(s[l++],s[r--]);
        }
        
        return s;
    }
};