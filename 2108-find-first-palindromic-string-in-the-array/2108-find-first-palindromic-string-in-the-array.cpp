class Solution {
public:    
    string firstPalindrome(vector<string>& words) {
        // string res;
        int i=0;
        
        for(i=0;i<words.size();i++){
            int l=0,r=words[i].size()-1;;
        
            while(l<=r){
                if(words[i][l]!=words[i][r]) break;
                l++,r--;
            }
            
            if(l>r) return words[i];
        }
        
        return "";
    }
};