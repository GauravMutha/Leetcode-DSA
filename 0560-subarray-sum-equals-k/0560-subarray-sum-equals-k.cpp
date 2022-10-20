class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i=0,j=0,sum=0,res=0;
        unordered_map<int,int>m{{0,1}};
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(m.count(sum-k)) res+=m[sum-k];
            m[sum]++;
        }
        return res;
    }
};

//prefix sum method