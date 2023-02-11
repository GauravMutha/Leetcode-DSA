//sort then binary search
class Solution {
public:
    vector<int> targetIndices(vector<int>& v, int target) {
        vector<int>res;
        
        sort(begin(v),end(v));
        int n=v.size();
        
        auto first =lower_bound(begin(v),end(v),target)-v.begin();
        auto last =upper_bound(begin(v),end(v),target)-v.begin()-1;
        
        if(first>=n || last>=n || first<0 || last<0
          || target!=v[first]||target!=v[last])
            return {};
        
        for(int i=first ; i<=last ; i++) 
            res.push_back(i);
        
        return res;
    }
};