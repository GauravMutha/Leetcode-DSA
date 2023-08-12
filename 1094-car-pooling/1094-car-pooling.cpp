typedef pair<int,int>pii; 
class Solution {
public:
    bool carPooling(vector<vector<int>>& vec, int cap) {
        
        auto max_drop = (*std::max_element(begin(vec), end(vec), [](auto& a, auto& b){ return a[2] < b[2]; }))[2];
        vector<int>stops(max_drop+1,0);
        int curr=0;
        for(int i=0;i<vec.size();i++){
            stops[vec[i][1]]+=vec[i][0];
            stops[vec[i][2]]-=vec[i][0];
        }
        
        for(int i=0;i<stops.size();i++){
            curr+=stops[i];
            if(curr>cap) return false;
        }
        
        return true;
    }
};