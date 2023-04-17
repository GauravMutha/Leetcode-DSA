//Simple Backtracking similar to printing subsets.
//Single recursion call inside a for loop
class Solution {
private: 
    vector<long long>ans;
public:
    void helper(long long start,vector<long long>& ds,long long target){
        if(target<=0){
            if(target==0)ans = vector<long long>(ds.begin(), ds.end());
            return;
        }
        for(long long i=start;i<=target && ans.size()==0;i+=2){
            ds.push_back(i);
            helper(i+2,ds,target-i);
            ds.pop_back();
        }
    }
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2) return {};
        vector<long long>ds;
        helper(2,ds,finalSum);
        
        return ans;
    }
};