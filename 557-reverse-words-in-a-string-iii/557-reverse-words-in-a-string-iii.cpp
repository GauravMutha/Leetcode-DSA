class Solution {
public:
    string reverseWords(string s) {
        int l=0,r=0;
        s.push_back(' ');
        for(int i=0;i<=s.size();i++){
            if(s[i]!=32)continue;
            r=i-1;
            while(l<r){
                swap(s[l],s[r]);
                l++ , r--;
            }
            l=i+1;
        }
        s.pop_back();
        return s;
    }
};