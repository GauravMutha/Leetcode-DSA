class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>m;
        
        for(int i=0;i<n;i++) m[nums[i]].push_back(i);
        
        int res=INT_MAX;
        
        for(auto &[num,pos]:m){
            pos.push_back(pos[0]+nums.size());
            int maxGap=INT_MIN;
            for(int i=1;i<pos.size();i++)
                maxGap=max(maxGap,(pos[i]-pos[i-1])/2);
            res=min(res,maxGap);
        }
        
        return res;
    }
};