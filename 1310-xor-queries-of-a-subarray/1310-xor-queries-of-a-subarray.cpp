class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
         vector<int>prexor(arr.size(),0);
        prexor[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            prexor[i]=prexor[i-1]^arr[i];
        }
        for(int i=0;i<queries.size();i++){
            int num=0;
            num=prexor[queries[i][0]]^prexor[queries[i][1]]^arr[queries[i][0]];
            ans.push_back(num);
        }
        return ans;
    }
};