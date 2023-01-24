//Brute Force O(n^2)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++)
                ans=max((nums[i]-1)*(nums[j]-1),ans);
        }
        return ans;
    }
};