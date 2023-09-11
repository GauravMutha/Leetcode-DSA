class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupsizes) {
        int n=groupsizes.size();
        vector<vector<int>>res;
        unordered_map<int,vector<int>>m;
        
        for(int i=0;i<n;i++) m[groupsizes[i]].push_back(i);
        
        for(auto &[k,vec] : m){
            vector<int>ds;
            for(int i=0;i<vec.size();i++){
                ds.push_back(vec[i]);
                if(ds.size()<k) continue;
                res.push_back(ds);
                ds={};
            }
        }
        
        return res;
    }
};