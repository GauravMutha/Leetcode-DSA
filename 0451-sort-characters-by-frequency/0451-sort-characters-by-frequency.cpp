//Hash table + comparator
class Solution {
public:
    string frequencySort(string s) {
        vector<int>hash(128);
        for(auto c: s) hash[c]++;
    
        sort(begin(s),end(s),[&](char a,char b){
            return ( (hash[a]>hash[b]) || (hash[a]==hash[b] && a<b) );
        });
        
        return s;
    }
};