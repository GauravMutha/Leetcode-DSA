class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptr1=0,ptr2=0;
        if(s.size()==0) return true;
        for(;ptr2<s.size() && ptr1<t.size();ptr1++){
            if(s[ptr2]==t[ptr1]) ptr2++;
            if(ptr2>=s.size()) return true;
        }
        
        return false;
    }
};