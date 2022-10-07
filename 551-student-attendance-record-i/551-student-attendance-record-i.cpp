class Solution {
public:
    bool checkRecord(string s) {
        return ((count(begin(s),end(s),'A')<2) && (s.find("LLL")==-1) );
    }
};