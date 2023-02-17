//brute force
//TC-->O(n^2+n*log(n))
//SC-->O(n^2)
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>sortedSubSum;
        int res=0;
        
        for(int i=0;i<nums.size();i++){
            int preSum=0;
            for(int j=i;j<nums.size();j++){
                preSum+=nums[j];
                sortedSubSum.push_back(preSum);
            }
        }
        
        sort(sortedSubSum.begin(),sortedSubSum.end());
        res=accumulate(sortedSubSum.begin()+left-1,sortedSubSum.begin()+right,0LL) % 1000000007;
        
        return res;
        
    }
};