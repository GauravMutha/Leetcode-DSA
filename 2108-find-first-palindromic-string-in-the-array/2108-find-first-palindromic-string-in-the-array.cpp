class Solution {
public:    
    string firstPalindrome(vector<string>& words) {
        
        for(auto str : words){
            if(str==string(str.rbegin(),str.rend()))
                return str;
        }
        
        return "";
    }
};