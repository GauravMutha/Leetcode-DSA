//Greedy
//No Recursion
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2) return {};
        vector<long long>ans;
        long long currSum=0,i=2;
        while((currSum+i)<=finalSum){
            ans.push_back(i);
            currSum+=i;
            i+=2;
        }
        ans[ans.size()-1]+=(finalSum-currSum);
        
        return ans;
        
    }
};