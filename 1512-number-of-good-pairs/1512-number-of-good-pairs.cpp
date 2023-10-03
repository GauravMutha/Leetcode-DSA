class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>m;
        int res=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(m.find(nums[i])!=m.end()) res+=m[nums[i]];
            m[nums[i]]++;
        }
        return res;
    }
};