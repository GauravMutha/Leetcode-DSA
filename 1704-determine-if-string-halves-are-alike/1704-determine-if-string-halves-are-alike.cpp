class Solution {
public:
    bool halvesAreAlike(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==65 || s[i]==69 || s[i]==73 || s[i]==79 || s[i]==85
              || s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117){
                count+= (i>=(s.size()/2)) ? -1:1;
            }
        }
        return (count==0);
    }
};