class Solution {
public:
 vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        for(auto elem:encoded){
           ans.push_back(first^=elem);
        }
        return ans;
    }

};