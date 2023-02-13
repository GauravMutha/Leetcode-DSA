//sorting + binary search
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(begin(nums),end(nums));
        vector<int>preSum(nums.size(),0), res(queries.size());
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i] , preSum[i]=sum;
        
        for(int i=0;i<queries.size();i++){
            int start=0 , end=preSum.size()-1, target=queries[i];;
            while(start<=end){
                int mid=start+ (end-start)/2;
                
                if(preSum[mid]<=target)
                    res[i]=mid+1 , start=mid+1;
                else end=mid-1;
            }
        }
        return res;
    }
};