class Solution {
public:
vector<int> circularPermutation(int n, int start) {
        vector<int>res;
        int x=pow(2,n);
        for(int i=0;i<x;i++){
            res.push_back(start^i^i>>1);
        }
    return res;
    } 
};