class Solution {
public:
    string greatestLetter(string s) {
        vector<int>lower(26),upper(26);
        string res="";
        for(auto c :s)
            (c<91) ? upper[c-'A']++ : lower[c-'a']++;
        
        for(int i=25;i>=0;i--)
            if(lower[i] && upper[i]){
                res+=(i+'A');
                break;
            }
        
        return res;
    }
};