//Using formula
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>ans;
        for(int i=0;i<pow(2,n);i++){
            int code=i^(i>>1);
            ans.push_back(code);
        }
        return ans;
    }
};