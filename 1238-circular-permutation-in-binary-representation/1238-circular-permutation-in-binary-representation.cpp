//using formula
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int>ans;
        for(int i=0;i<pow(2,n);i++){
            int code=start^i^(i>>1);
            ans.push_back(code);
        }
        
        return ans;
    }
};