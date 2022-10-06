class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int l=0,r=0;
        s.push_back(' ');
        vector<vector<int>>res;
        for(;r<=s.size();r++){
            if(s[r]!=s[l] || r==(s.size()-1)){
                if((r-l)>=3) res.push_back({l,r-1});
                l=r;
            }
        }
        return res;
    }
};