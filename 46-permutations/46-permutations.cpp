class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>freq(nums.size(),0);
        perm(nums,res,freq);
        return res;
    }
    
    void perm(vector<int>& nums,vector<vector<int>>& res,vector<int>& freq){
        static vector<int>ds;
        if(ds.size()==nums.size()){
            res.push_back(ds);
            return;
        }
        
        for(int i=0;i<freq.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                
                perm(nums,res,freq);
                
                
                ds.pop_back();
                freq[i]=0;
            }
        }
    }
};