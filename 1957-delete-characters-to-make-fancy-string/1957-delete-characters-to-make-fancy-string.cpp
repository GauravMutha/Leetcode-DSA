class Solution {
public:
    string makeFancyString(string s) {
        int l=0,r=0,count=0;
        string res;
        for(;r<s.size();r++){
            if(s[l]!=s[r])
                count=0,l=r;            
            count++;
            if(count<3)
                res.push_back(s[l]);
        }
        return res;
    }
};