//Simple Backtracking similar to printing subsets.
//classic two recursion call pick not pick method
class Solution {
private: 
    vector<long long>ans;
public:
    bool helper(long long i,long long target){
        if(target==0) return true;
        if(target<i) return false;
        ans.push_back(i);
        if(helper(i+2,target-i)) return true;
        ans.pop_back();
        return helper(i+2,target);
    }
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2) return {};
        vector<long long>ds;
        helper(2,finalSum);
        
        return ans;
    }
};