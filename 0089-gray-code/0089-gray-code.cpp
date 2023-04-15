//Using recursion + Bit manipulation
//Pepcoding(Sumit Malik sir)
class Solution {
public:
    vector<int> generate(int n){
        if(n==0) return {0};
        vector<int> vec=generate(n-1);
        int mask=1<<(n-1) , sz=vec.size();
        for(int i=sz-1;i>=0;i--){
            int temp=vec[i];
            temp|=mask;
            vec.push_back(temp);
        }
        return vec;
    }
    vector<int> grayCode(int n) {
        return generate(n);
    }
};