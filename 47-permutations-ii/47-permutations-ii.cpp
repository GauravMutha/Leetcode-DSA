class Solution {
public:
    vector<vector<int>>ans;
    map<int,int>m;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>ds;
        for(auto elem:nums)
            m[elem]++;
        permute(ds,nums.size());
        
        return ans;
    }
    
    void permute(vector<int>ds,int index){
        if(index<=0){
            ans.push_back(ds);
            return;
        }
        for(auto &[key,value]:m){
            if(value<=0)continue;
            ds.push_back(key);
            value--;
            permute(ds,index-1);
            ds.pop_back();
            value++;
        }
    }
};