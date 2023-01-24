//Map+pair vector + comparator
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        vector<pair<int,char>>vec;
        for(auto c: s) m[c]++;
        
        for(auto &[c,freq]:m)
            vec.push_back({freq,c});
        
        sort(begin(vec),end(vec),[](const auto &a,const auto &b){
            return a.first>b.first;
        });
        
        string ans;
        for(auto &[freq,c] : vec)
            ans.append(freq,c);
        
        return ans;
    }
};