class Solution {
public:
    bool isValid(string s) {
        string res;
        for(int i=0;i<s.size();i++){
            if(s[i]=='c'){
                int n=res.size();
                if(n<2 || res[n-1]!='b' || res[n-2]!='a') return false;
                res.pop_back() , res.pop_back();
            }
            else res.push_back(s[i]);
        }
        return (res.size()==0);  
    }
};
//Previous code uses both string and stack BUT THIS uses only string
//SC-->O(n)
//TC--> O(n)