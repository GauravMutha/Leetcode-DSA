class Solution {
public:
    int countAsterisks(string s) {
        int barCount=0,res=0;
        
        for(int i=0;i<s.size();i++){
            if(barCount==0 && s[i]=='*')res++;
            else{
                if(s[i]=='|')barCount++;
                barCount%=2;
            }
        }
        return res;
    }
};