class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        comsum(candidates,res,target,0);
        return res;
    }
    
    void comsum(vector<int>& candidates,vector<vector<int>>& res,int target,int i){
        static vector<int>ds;
        
        if(target<0)
            return;
        if(target==0){
            res.push_back(ds);
            return;
        }
        if(i==candidates.size())
            return;
        
        ds.push_back(candidates[i]);
        comsum(candidates,res,target-candidates[i],i);
        ds.pop_back();
        comsum(candidates,res,target,i+1);
    }
};