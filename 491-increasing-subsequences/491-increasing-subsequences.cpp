class Solution {
public:
    set<vector<int>>s;
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>res;
        picknotpick(nums,ds,0);
        res.assign(s.begin(),s.end());
        
        return res;
    }
    
    void picknotpick(vector<int>& nums,vector<int>& ds, int i){

    if(i>=nums.size()){
        if(ds.size()>1)s.insert(ds);
        return;
    }
    if(ds.empty() || ds.back()<= nums[i]){
        ds.push_back(nums[i]);
        picknotpick(nums,ds,i+1);
        ds.pop_back();
    }
    picknotpick(nums,ds,i+1);
}
};