//Priority Queue + Hash Table
//3 pass
class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>>maxh;
        vector<int>hash(127,0);
        int i=0;
        for(auto c : s) hash[c]++;
        
        for(int i=0;i<127;i++) 
            if(hash[i]) maxh.push({hash[i],i});
        
        while(!maxh.empty()){
            int k=maxh.top().first;
            while(k--) s[i++]=maxh.top().second;
            maxh.pop();
        }
        return s;
    }
};