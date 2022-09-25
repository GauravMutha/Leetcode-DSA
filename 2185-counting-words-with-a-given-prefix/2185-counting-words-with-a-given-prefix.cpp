class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0,n=pref.size();
        for(auto str : words)
            if(str.substr(0,n)==pref) count++;
         return count;
    }
};