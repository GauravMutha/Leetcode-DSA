//Map
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto num : nums) if(num) m[num]++;
        return m.size();
    }
};