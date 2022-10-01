class Solution {
public:
    int maxPower(string s) {
        int l=0,r=0,res=1;
        
        while(r<s.size()){
            if(s[l]==s[r]){
                res=max(r-l+1,res);
                r++;
            }
            else
                l=r;
        }
        return res;
    }
};