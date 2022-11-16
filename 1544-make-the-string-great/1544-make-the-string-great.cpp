class Solution {
public:
    string makeGood(string s) {
        string res="";
        for(int i=0;i<s.size();i++){
            bool flag;
            if(res.size()==0) res.push_back(s[i]);
            else{
                flag=(islower(s[i]))?(s[i]==res.back()+32):(s[i]==res.back()-32);
                if(flag) res.pop_back();
                else res.push_back(s[i]);
            }
        }
        return res;
    }
};
//TC-->O(n)
//SC-->O(1)