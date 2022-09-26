class Solution {
public:
int countPrefixes(vector<string>& words, string s) {
    int count=0;
        for(auto str:words){
            count+= (str==(s.substr(0,str.size())));
        }
    
    return count;
    }
};