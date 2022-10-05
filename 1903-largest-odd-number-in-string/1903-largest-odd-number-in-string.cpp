class Solution {
public:
    string largestOddNumber(string num) {
        if((num.back()-'0')%2) return num;
        int i=0;
        for(i=num.size()-1;i>=0;i--)
            if((num[i]-'0')%2) return num.substr(0,i+1);
        
        return "";
    }
};