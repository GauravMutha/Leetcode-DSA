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
            if(r<vec.size() && j==vec[r]){
                l=r;
                r++;
            }
            
            if(r==vec.size())
                res[j]=j-vec[l];
            else
                res[j]= min(abs(j-vec[l]) , abs(j-vec[r]));

        }
        
        return res;
    }
};