//Using the generalized k-sum solution
//Similar approach to the previous submission
class Solution {
private:
    vector<vector<int>>res;
public:
    void dfs(int l,int r,long long target,int k,vector<int>& path,vector<int>& nums){
        if(k==2){
            while(l<r){
                long long sum=(long long)nums[l]+(long long)nums[r];
                if(sum>target) r--;
                else if(sum<target) l++;
                else{
                    path.push_back(nums[l]);
                    path.push_back(nums[r]);
                    res.push_back(path);
                    path.pop_back();
                    path.pop_back();
                    
                    while (l+1 < r && nums[l] == nums[l+1]) ++l;
                    ++l; --r;
                }
            }
        }
        for(int i=l;i<r;i++){
            if(i>l && nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            dfs(i+1,r,target-(long long)nums[i],k-1,path,nums);
            path.pop_back();
        }
    }
    void kSum(vector<int>&nums,int target,int k){
        vector<int>tmp;
        dfs(0,(int)nums.size()-1,(long long)target,k,tmp,nums);
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return res; //an empty res is returned
        sort(nums.begin(),nums.end());
        
        kSum(nums,target,4);
        
        return res;
    }
};