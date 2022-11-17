class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0 , maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            maxi=INT_MIN , mini=INT_MAX;
            for(int j=i;j<nums.size();j++){
                mini=min(mini,(long long)nums[j]);
                maxi=max(maxi,(long long)nums[j]);
                sum+=maxi-mini;
            }
        }
        return sum;
    }
};

//O(n^2) Brute force