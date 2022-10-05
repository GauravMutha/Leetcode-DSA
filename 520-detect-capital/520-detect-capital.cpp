class Solution {
public:
    bool detectCapitalUse(string word) {
        char c=word.back();
        if(isupper(c)){
            for(auto c:word)
                if(islower(c)) return false;
            return true;
        }
        else{
            for(int i=word.size()-1;i>0;i--)
                if(isupper(word[i])) return false;
            return true;
        }
    }
};