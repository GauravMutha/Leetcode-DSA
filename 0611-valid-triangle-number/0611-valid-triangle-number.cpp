//Binary search using lower_bound
//O(N^2(log(N))+ Nlog(N))
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res=0;
        sort(begin(nums),end(nums));
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size()-1;j++){
                auto it=lower_bound(begin(nums)+j+1,end(nums),nums[i]+nums[j]);
                int k=it-nums.begin();
                res+=(k-j-1);
            }
        }
        return res;
    }
};