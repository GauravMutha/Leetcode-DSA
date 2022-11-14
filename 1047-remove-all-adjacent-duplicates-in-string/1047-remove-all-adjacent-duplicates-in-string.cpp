class Solution {
public:
    string removeDuplicates(string s) {
        int i=0;
        for(int j=0;j<s.size();i++,j++){
            s[i]=s[j];
            if(i>0 && s[i-1]==s[i]) i-=2;
        }
        return s.substr(0,i);
    }
};

//Two pointers
//O(1) Space complexity