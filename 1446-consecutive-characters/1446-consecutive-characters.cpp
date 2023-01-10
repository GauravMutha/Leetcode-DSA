class Solution {
public:
    int maxPower(string s) {
        int l=0,r=1,res=1;
        while(r<s.size()){
            if(s[l]==s[r])
                res=max(res,r-l+1);
            else l=r;
            r++;
        }
        return res;
    }
};