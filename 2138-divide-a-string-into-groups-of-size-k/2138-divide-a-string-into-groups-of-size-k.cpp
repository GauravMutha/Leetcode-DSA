class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n;
        string temp;
        vector<string>res;
        if((s.size()%k)!=0){
            n=k-(s.size()%k);
            s+=string(n,fill);
        }
        
        for(int i=0;i<=s.size();i++){
            if( i!=0 && ( (i%k)==0) ){
                res.push_back(temp);
                temp="";
            }
            temp+=s[i];
        }
        return res;
    }
};