//binarys search + sum
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum=0;
        int n=chalk.size();
        vector<long>preSum;
        for(auto &c:chalk)
            sum+=c , preSum.push_back(sum);
        k%=sum;
        int i=lower_bound(begin(preSum),end(preSum),k)-begin(preSum);
        if(preSum[i]==k) return (i+1)%n;
        return i;
    }
};