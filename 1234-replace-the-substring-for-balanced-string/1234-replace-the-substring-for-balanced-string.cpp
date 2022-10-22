class Solution {
public:
    int balancedString(string s) {
        unordered_map<char,int>count;
        int r=0,l=0,res=INT_MAX,n=s.size(),m=n/4;
        for(auto c:s) count[c]++;
        while(r<n){
            count[s[r]]--;
            while(l<n && count['Q']<=m && count['W']<=m && count['E']<=m && count['R']<=m){
                if(l>r) return 0;
                count[s[l]]++;
                res=min(res,r-l+1);
                l++;
            }
            r++;
        }
        return res;
    }
};