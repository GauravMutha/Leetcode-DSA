class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int>num;
        string val="";
        int preval=-1;
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])) continue;
            
            else if(isdigit(s[i])){
                val+=s[i];
                if((i+1)==s.size() || s[i+1]==' '){
                    int currval=stoi(val);
                    if(preval>=currval) return false;
                    preval=currval;
                    val="";
                }
            }
        }
        return true;
    }
};