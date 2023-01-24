//map + vector pair +priority queue(min heap) 
typedef pair<int,int> pii;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pii,vector<pii>,greater<pii>>mh;
        unordered_map<int,int>m;
        vector<int>res;
        vector<pii>vec;
        for(auto &e: nums) m[e]++;
        
        for(auto &[num,freq]:m) vec.push_back({freq,num});
        
        for(int i=0;i<vec.size();i++){
            mh.push(vec[i]);
            if(mh.size()>k) mh.pop();
        }
        
        while(!mh.empty())
            res.push_back(mh.top().second) ,mh.pop();
        
        return res;
    }
};