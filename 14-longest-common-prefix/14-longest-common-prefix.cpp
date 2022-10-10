class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        sort(begin(strs),end(strs));
        int i=0,j=0;
        string res="",s1=strs[0],s2=strs.back();
        
        while(i<s1.size() && i<s2.size()){
            if(s1[i]==s2[i]) res.push_back(s1[i]);
            else break;
            i++;
        }
        return res;
    }
};

//Find two shortest string by sort method , then just their common prefix