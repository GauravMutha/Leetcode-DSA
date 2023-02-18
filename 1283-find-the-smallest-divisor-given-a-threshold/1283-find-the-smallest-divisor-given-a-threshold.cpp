class Solution {
    bool good(int x, vector<int> &nums, int t) {
        int sum = 0;
        for(int i : nums) sum += ceil((double) i / x);
        return sum > t ? false : true;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1, e = 1e9, ans = INT_MAX;
        while(s <= e) {
            int m = (s + e) / 2;
            if(good(m, nums, threshold)) ans = m, e = m - 1;
            else s = m + 1;
        }
        return ans;
    }
};