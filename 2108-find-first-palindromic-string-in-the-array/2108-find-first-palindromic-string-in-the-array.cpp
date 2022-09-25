class Solution {
public:    
    string firstPalindrome(vector<string>& words) {
        string res;
        
        for(auto str : words){
            res=str;
            reverse(res.begin(),res.end());
            if(res==str) return res;
        }
        
        return "";
    }
};