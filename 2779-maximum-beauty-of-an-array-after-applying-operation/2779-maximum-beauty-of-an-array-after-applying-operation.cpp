//Line sweep algorithm
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        
        vector<pair<int,int>>intervals;
        int ans=0,n=nums.size(),count=0;
        map<int,int>m;
        
        sort(begin(nums),end(nums));
        
        for(int i=0;i<n;i++){
            intervals.push_back({nums[i]-k,nums[i]+k});
            m[nums[i]-k]++;
            m[nums[i]+k+1]--;
        }
        
        for(auto &[point,mark]:m){
            count+=mark;
            ans=max(ans,count);
        }
        return ans;
    }
};