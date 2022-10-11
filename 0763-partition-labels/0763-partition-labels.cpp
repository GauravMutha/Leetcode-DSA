class Solution {
public:
    vector<int> partitionLabels(string s) {
        int r=0,l=0;
        vector<int>res;
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]=i;
        }
        
        r=m[s[l]];
        for(int i=0;i<s.size();i++){
            if(i==r){
                res.push_back(r-l+1);
                l=i+1;
                r=m[s[l]];
            } 
            else if(m[s[i]]<r) continue;
            else if(m[s[i]]>r){
                r=m[s[i]];
            }
        }
        return res;
    }
};