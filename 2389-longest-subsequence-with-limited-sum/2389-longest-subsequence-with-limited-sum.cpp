//sorting + linear search
//brute force
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(begin(nums),end(nums));
        vector<int>preSum(nums.size(),0), res(queries.size());
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i] , preSum[i]=sum;
        
        for(int i=0;i<queries.size();i++){
            for(int j=0;j<nums.size();j++){
                if(preSum[j]<=queries[i]) res[i]=(j+1);
                else break;
            }
        }
        return res;
    }
};