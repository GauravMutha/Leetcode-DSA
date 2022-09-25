class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> uset;
        
        for(auto start : paths){
            uset.insert(start[0]);
        }
        
        for(auto end:paths){
            if(!uset.count(end[1])) return end[1]; 
        }
        
        return "";
    }
};