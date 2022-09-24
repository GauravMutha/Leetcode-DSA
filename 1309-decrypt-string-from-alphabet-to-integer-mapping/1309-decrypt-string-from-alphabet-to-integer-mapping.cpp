class Solution {
public:
    string freqAlphabets(string s) {
         string res;
        for(int i=0;i<s.size();){
            if(i<s.size()-2 && s[i+2]=='#'){
                res+='a'-1+(s[i]-'0')*10 + (s[i+1]-'0');
                i+=3;
            }
            else{
                res+=s[i]+48;
                i++;
            }
                
        }
        return res;
    }
};