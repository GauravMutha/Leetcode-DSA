//No sorting - Hash table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<long,int>m;
        for(int i=0;i<nums.size();i++){
            long require=(long)(target-nums[i]);
            if(m.find(require)!=m.end())
                return vector<int>({i,m[require]});
            m[nums[i]]=i;
        }
        
        return {};
    }
};