class Solution {
public:
    char findTheDifference(string s, string t) {
        int num=0;
        
        for(int i=0;i<s.length();i++){
            int helper=1;
            helper<<=s[i]-97;
            if(helper&num){
                num&=~(1<<(s[i]-97));
            }
            else{
                num|=helper;
            }
        }
         for(int i=0;i<t.length();i++){
            int helper=1;
            helper<<=t[i]-97;
            if(helper&num){
                num&=~(1<<(t[i]-97));
            }
            else{
                num|=helper;
            }
        }
        return (char)((int)log2(num)+97);
    }
};