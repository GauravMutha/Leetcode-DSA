//Naive
//Sorting
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size()==1) return strs[0];
        
        sort(begin(strs),end(strs));
        int i=0;
        
        string str1=strs[0] , str2=strs.back();;
        for(auto s:strs) cout<<s<<" ";
        for(i=0;i<str1.size() && i<str2.size();i++)
            if(str1[i]!=str2[i]) break;
        cout<<i;
        return str1.substr(0,i);
    }
};