class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        
        comsum3(res,k,n,1,9);
        
        return res;
    }
    
    void comsum3(vector<vector<int>>& res,int k,int n,int start,int end){
        static vector<int>ds;
        
        if(ds.size()==k && n==0){
            res.push_back(ds);
            return;
        }
        
        for(int i=start;i<=9;i++){
            ds.push_back(i);
            comsum3(res,k,n-i,i+1,end);
            ds.pop_back();
        }
    }
};