class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>m;
        int res=0,flago=0;
        for(auto c:s)
            m[c]++;
        for(auto &[key,value] : m){
            if(value%2==1)
                res+=(value-1),flago=1;
            else
                res+=value;
        }
        return (res+flago);
    }
};