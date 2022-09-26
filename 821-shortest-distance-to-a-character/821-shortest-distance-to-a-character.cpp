class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>res(s.size(),0);
        vector<int> vec;
        int j=0,l=0,r=0;
        
        for(int i=0;i<s.size();i++)
            if(s[i]==c) vec.push_back(i);
        
        if(vec.size()==s.size()) return res;
        
        for(j=0; j<s.size() ; j++){
            if(j==vec[r]){
                l=r;
                r++;
            }
            
            if(r==vec.size()) break;
            
            res[j]= min(abs(j-vec[l]) , abs(j-vec[r]));
        }
        
        for(;j<s.size();j++)
            res[j]=abs(j-vec[l]);
        
        return res;
    }
};