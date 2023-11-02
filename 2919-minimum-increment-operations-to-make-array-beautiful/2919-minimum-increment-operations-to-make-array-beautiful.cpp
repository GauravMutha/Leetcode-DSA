class Solution {
public:
        long long minIncrementOperations(vector<int>& A, int k) {
        long long dp1 = 0, dp2 = 0, dp3 = 0, dp;
        for (int& a: A) {
            dp = min(dp1, min(dp2, dp3)) + max(k - a, 0);
            dp1 = dp2;
            dp2 = dp3;
            dp3 = dp;
        }
        return min(dp1, min(dp2, dp3));
    }
};