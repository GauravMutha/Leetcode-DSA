class Solution {
public:
    bool palinWithin(string s,int l ,int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++,r--;
        }
        return true;
    }
    bool validate(string a,string b){
        int l=0,r=b.size()-1;
        
        while(l<r){
            if(a[l]!=b[r])
                break;
            l++,r--;
        }
         return palinWithin(a,l,r) || palinWithin(b,l,r);
    }
    bool checkPalindromeFormation(string a, string b) {
        return validate(a,b) || validate(b,a);
    }
};