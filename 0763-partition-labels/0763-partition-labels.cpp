class Solution {
public:
    vector<int> partitionLabels(string s) {
        int pre_r=-1,r=0;
        vector<int>res,m(26,0);
        for(int i=0;i<s.size();i++){
            m[s[i]-'a']=i;
        }
        
        for(int i=0;i<s.size();i++){
            r=max(m[s[i]-'a'],r);
            if(i==r){
                res.push_back(r-pre_r);
                pre_r=r;
            }
        }
        return res;
    }
};

//using hash array of size 26 instead of map