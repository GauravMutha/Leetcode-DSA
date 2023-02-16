//using hash table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        unordered_map<long,int>m;
        long require=0;
        
        for(int i=0;i<nums.size();i++){
            require=long(k-nums[i]);
            if(m.count(require)) 
                return vector<int>({m[require],i});
            
            m[nums[i]]=i;
        }
        
        return {};
    }
};