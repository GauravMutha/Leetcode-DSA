class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>m;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        unordered_map<int, int>::iterator itr;
        for(itr=m.begin();itr!=m.end();itr++){
            if((itr->second)==1)ans.push_back(itr->first);
        }
        return ans;
    }
};

//TC--->O(n)
//SC--->O(n)