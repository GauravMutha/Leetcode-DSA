class Solution {
public:
    bool canChange(string s, string t) {
        int n=t.size(),i=0,j=0;
        string a,b;
        vector<int>ls,lt,rs,rt;
        for(int i=0;i<n;i++){
            if(s[i]!='_') a+=s[i];
            if(t[i]!='_') b+=t[i];
        }
        if(a!=b) return false;
        
        for(int i=0;i<n;i++){
            if(s[i]=='L') ls.push_back(i);
            if(t[i]=='L') lt.push_back(i);
            if(s[i]=='R') rs.push_back(i);
            if(t[i]=='R') rt.push_back(i);
        }
        
        for(int i=0;i<ls.size();i++) if(ls[i]<lt[i]) return false;
        for(int i=0;i<rs.size();i++) if(rs[i]>rt[i]) return false;
        
        return true;
    }
};

//4 pass solution
//we will check twi things :
//a)relative order of R and L are same in both string
//b)will store vector indices of R and L separately and then check if 
//if any index of L in s is less than in t and reverse for r , b return false

//if both a and b condition return true then only the answer is true

//TC-->O(n) SC-->O(n)