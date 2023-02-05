//Without map
//O(N)
class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        vector<int>hash(26,0);
        string res="";
        int i=0;
        bool onlyOne=false;
        for(auto &ch : s) hash[ch-'a']++;
        
        while(true){
            i=25;
            onlyOne=false;
            for(;i>=0;i--){
                if(res.size()>0 && (res.back()-'a')==i && hash[i]){
                    onlyOne=true;
                    continue;
                }
                if(hash[i]>0) break;
            }
            if(i<0) break;
            
            int freq= onlyOne ? 1 : min(hash[i],limit);
            hash[i]-=freq;
            while(freq--) res.push_back(i+'a');
        }
        
        return res;
    }
};