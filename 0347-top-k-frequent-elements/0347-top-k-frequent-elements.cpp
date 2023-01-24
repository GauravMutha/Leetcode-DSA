//Map + Vector pair + comparator
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        vector<int>res;
        vector<pair<int,int>>vec;
        for(auto &e: nums) m[e]++;
        
        for(auto &[num,freq]:m) vec.push_back({freq,num});
        
        sort(begin(vec),end(vec),[](const auto &a, const auto &b){
            return a.first>b.first;
        });
        
        for(int i=0;i<vec.size() && k;k--,i++)
            res.push_back(vec[i].second);
        
        return res;
    }
};