class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string>res;
        string str="";
        for(char j=s[0];j<=s[3];j++)
            for(char i=s[1];i<=s[4];i++)
                res.push_back(string(1, j) + i);
        return res;
    }
};