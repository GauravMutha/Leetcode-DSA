class Solution {
public:
    bool subset(string str , string s){
        int i=0,j=0;
        while(i<str.size() && j<s.size()){
            if(str[i]==s[j]) i++;
            j++;
        }
        return (i==str.size());
    }
    string findLongestWord(string s, vector<string>& dict) {
        string res="";
        for(auto str : dict){
            if(subset(str,s)){
                if(str.size() > res.size() || (str.size()==res.size() && str<res)) res=str;
            }
        }
        return res;
    }
};