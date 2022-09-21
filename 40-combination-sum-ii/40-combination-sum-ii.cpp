class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ds;
        int i=0;
        sort(candidates.begin(),candidates.end());
        comsum2(candidates,ds,target,i);
        
        return ans;
    }
    
    void comsum2(vector<int>candidates,vector<int>& ds,int target,int start){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        if(target<0)
            return;
        
       for(int i=start;i<candidates.size();i++){
           if(i>start && candidates[i]==candidates[i-1])continue;
           ds.push_back(candidates[i]);
           comsum2(candidates,ds,target-candidates[i],i+1);
           ds.pop_back();
       }
    }
};