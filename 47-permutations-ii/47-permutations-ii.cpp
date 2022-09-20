class Solution {
public:
    vector<vector<int>>ans;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>ds; 
        vector<int>freq(nums.size(),0);
        sort(nums.begin(),nums.end());
        permute(ds,nums,freq);
        
        return ans;
    }
    
    void permute(vector<int>& ds,vector<int>& nums,vector<int>& freq){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i])continue;
            if(i>0 && nums[i]==nums[i-1] && freq[i-1])continue;
            freq[i]=1;
            ds.push_back(nums[i]);
            
            permute(ds,nums,freq);
            
            ds.pop_back();
            freq[i]=0;
        }
    }
};