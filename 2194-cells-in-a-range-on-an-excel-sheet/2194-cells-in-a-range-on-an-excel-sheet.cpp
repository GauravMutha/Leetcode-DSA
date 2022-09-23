class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string>res;
        string str="";
        for(char j=s[0];j<=s[3];j++)
            for(char i=s[1];i<=s[4];i++){
                str.push_back(j);
                str.push_back(i);
                res.push_back(str);
                str="";
            }
        return res;
    }
};