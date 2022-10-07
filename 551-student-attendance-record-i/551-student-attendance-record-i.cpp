class Solution {
public:
    bool checkRecord(string s) {
        int i=0,r=0,countA=0;
        
        while(i<s.size()){
            if(s[i]=='A' || s[i]=='P') countA+=(s[i]=='A'),i++;
            else if(s[i]=='L'){
                r=i;
                while(r<s.size() && s[r]=='L') r++;
                if(r-i>2) return false;
                i=r;
            }
        }
        return (countA<2);
    }
};