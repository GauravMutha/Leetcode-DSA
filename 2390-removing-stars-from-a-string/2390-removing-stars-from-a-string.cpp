class Solution {
public:
    string removeStars(string s) {
        int i=0,j=0;
        for(int j=0;j<s.size();i++,j++){
            s[i]=s[j];
            if(s[j]=='*') i-=2;
        }
        return s.substr(0,i);
    }
};
//1 pass + Two pointers
//SC-->O(1)
//TC-->O(n)