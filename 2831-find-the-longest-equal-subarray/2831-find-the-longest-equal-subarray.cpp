//Sliding Window

class Solution {
public:
    int slide(vector<int>& idxVec,int k){
        int ans=1;
        
        for(int r=0,l=0;r<idxVec.size();r++){
            if((idxVec[r]-idxVec[l]-ans)<=k)
                ans=max(r-l+1,ans);
            else l++;
        }
        
        return ans;
    }
    int longestEqualSubarray(vector<int>& nums, int k) {
        
        int res=1;
        
        vector<vector<int>>hash(nums.size()+1);
        for(int i=0;i<nums.size();i++) hash[nums[i]].push_back(i);
        
        for(int i=0;i<hash.size();i++){
            if(hash[i].empty()) continue;
            int maxSubSize=slide(hash[i],k);
            res=max(maxSubSize,res);
        }
        
        return res;
    }
};