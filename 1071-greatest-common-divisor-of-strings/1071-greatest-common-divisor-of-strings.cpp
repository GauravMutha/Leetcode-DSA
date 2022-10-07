class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.size()<str2.size())
            return gcdOfStrings(str2,str1);
        
        else if(str1.find(str2)!=0) return "";
        else if(str2.empty()) return str1;
        else return gcdOfStrings(str1.substr(str2.size()),str2);
    }
};