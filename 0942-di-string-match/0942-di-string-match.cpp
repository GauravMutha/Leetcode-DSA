class Solution {
public:
    vector<int> diStringMatch(string s) {
        int minAvailable=0 , maxAvailable=s.size();
        vector<int>ans;
        for(auto c : s){
            if(c=='I') ans.push_back(minAvailable++);
            else ans.push_back(maxAvailable--);
        }
        ans.push_back(maxAvailable);
        return ans;
    }
};