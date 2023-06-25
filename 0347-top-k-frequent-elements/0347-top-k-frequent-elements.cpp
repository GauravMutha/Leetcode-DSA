typedef pair<int,int> pii; 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int>res;        
        vector<pii>vec;

        int n=nums.size();
        unordered_map<int,int>m;
        
        for(int i=0;i<n;i++) m[nums[i]]++;
        
        for(auto &[num,freq]:m) vec.push_back({freq,num});
        
        sort(begin(vec),end(vec),[](const auto &a,const auto &b){
            return a.first>b.first;
        });
        
        for(int i=0;k && i<n;i++,k--) res.push_back(vec[i].second);
        
        return res;
    }
};