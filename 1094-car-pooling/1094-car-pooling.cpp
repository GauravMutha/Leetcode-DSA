//Prefix Sum
//O(n) TC
//3 pass
class Solution {
public:
    bool carPooling(vector<vector<int>>& vec, int cap) {
        int in_car=0;
        auto max_drop = (*std::max_element(begin(vec), end(vec), [](auto& a, auto& b){ return a[2] < b[2]; }))[2];
        
        vector<int>stops(max_drop+1,0);
        
        for(int i=0;i<vec.size();i++){
            stops[vec[i][1]]+=vec[i][0];
            stops[vec[i][2]]-=vec[i][0];
        }
        
        for(int i=0;i<stops.size();i++){
            in_car+=stops[i];
            if(in_car>cap) return false;
        }
        return true;
        
    }
};