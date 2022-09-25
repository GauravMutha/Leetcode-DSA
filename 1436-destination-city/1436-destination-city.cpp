class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int>map;
        
        for(auto &vec : paths){
            map[vec[0]]+=1;
            map[vec[1]]+=0;
        }
        
        for(auto &[k,v] : map){
            if(v==0) return k;
        }
        
        return "";
    }
};