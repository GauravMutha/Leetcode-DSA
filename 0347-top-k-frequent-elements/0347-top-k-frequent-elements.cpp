typedef pair<int,int> pii; 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int>res;
        int n=nums.size();
        priority_queue<pii,vector<pii>,greater<pii>> minh;
        unordered_map<int,int>m;
        
        for(int i=0;i<n;i++) m[nums[i]]++;
        
        for(auto &[num,freq]:m){
            minh.push({freq,num});
            if(minh.size()>k) minh.pop();
        }
        
        while(k--) res.push_back(minh.top().second) , minh.pop();
        
        return res;
    }
};