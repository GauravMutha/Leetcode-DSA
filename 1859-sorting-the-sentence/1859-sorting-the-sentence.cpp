class Solution {
public:
    string sortSentence(string s) {
        vector<string>vec(9);
        string res,temp;
        
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])) temp+=s[i];
            else if(isdigit(s[i])){
                vec[(s[i]-'0')-1]=(temp+" ");
                temp="";
            }

        }
        for(auto str:vec){
            res+=str;
        }
        res.pop_back();
        return res;
    }
};