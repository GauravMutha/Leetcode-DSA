class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,end=s.size()-1,res=0;
        unordered_map<char,int>m;
        while(r<s.size()){
            m[s[r]]++;
            while(m['a'] && m['b'] && m['c']){
                res+=(1+(end-r));
                m[s[l]]--;
                l++;
            }
            r++;
        }
        return res;
    }
};

//sliding window
//TC--> O(n) SC-->O(1)