class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = cost.size();
        std::unordered_map<int, int> memo;

        return calculateCost(n, cost, memo);
    }

private:
    int calculateCost(int i, const std::vector<int>& cost, std::unordered_map<int, int>& memo) {
        if (i <= 1) {
            return 0;
        }
        if (memo.find(i) != memo.end()) {
            return memo[i];
        }
        int one_step_cost = cost[i - 1] + calculateCost(i - 1, cost, memo);
        int two_step_cost = cost[i - 2] + calculateCost(i - 2, cost, memo);
        memo[i] = std::min(one_step_cost, two_step_cost);
        return memo[i];
    }
};