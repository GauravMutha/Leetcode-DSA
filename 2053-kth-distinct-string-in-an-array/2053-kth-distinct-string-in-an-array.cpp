class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>m;
        
        for(auto str : arr)
            m[str]++;
        
        for(auto str : arr)
            if(m[str]==1 && --k==0) return str;
        
        return "";
    }
};