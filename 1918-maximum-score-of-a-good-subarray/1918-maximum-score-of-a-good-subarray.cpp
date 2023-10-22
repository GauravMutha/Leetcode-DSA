//Testing an extension
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> leftBoundary(n, -1); // Store the next lower element from the left.
        vector<int> rightBoundary(n, n); // Store the next lower element from the right.
        
        stack<int> leftStack; // Monotonic Stack to help calculate left array.
        stack<int> rightStack; // Monotonic Stack to help calculate right array.
        
        // Calculate next lower element from the left.
        for (int i = n - 1; i >= 0; i--) {
            while (!leftStack.empty() && nums[leftStack.top()] > nums[i]) {
                 // If the current element is smaller than elements in the stack,
                // set the left boundary for those elements to the current element's index.
                leftBoundary[leftStack.top()] = i;
                leftStack.pop();
            }
            leftStack.push(i);
        }
        
        // Calculate next lower element from the right
        for (int i = 0; i < n; i++) {
            while (!rightStack.empty() && nums[rightStack.top()] > nums[i]) {
                // If the current element is smaller than elements in the stack,
                // set the right boundary for those elements to the current element's index.
                rightBoundary[rightStack.top()] = i; 
                rightStack.pop();
            }
            rightStack.push(i);
        }
        
        int maxScore = 0; // Initialize the maximum score to 0.
        
        // Calculate the maximum score for good subarrays
        for (int i = 0; i < n; i++) {
            if (leftBoundary[i] < k && rightBoundary[i] > k) {
                // Calculate the score for the subarray that contains element 'k'.
                int subarrayScore = nums[i] * (rightBoundary[i] - leftBoundary[i] - 1);
                maxScore = max(maxScore, subarrayScore); // Update the maximum score.
            }
        }
        
        return maxScore; // Return the maximum score for a good subarray.
    }
};