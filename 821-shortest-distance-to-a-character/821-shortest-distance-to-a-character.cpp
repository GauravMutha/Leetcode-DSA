class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.size() , pos=-n;
        vector<int>res(s.size(),0);
        
        for(int i=0;i<s.size();i++){
            if(c==s[i]) pos=i;
            res[i]=i-pos;
        }
        
        for(int i=pos-1;i>=0;i--){
            if(c==s[i]) pos=i;
            res[i]=min(res[i],pos-i);
        }
        
        return res;
    }
};