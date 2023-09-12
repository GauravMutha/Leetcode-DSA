class Solution {
public:
    int minDeletions(string s) {
        int hash[26]={0}, res=0;
        vector<int>vec;
        for(auto c: s) hash[c-'a']++;
        for(int i=0;i<26;i++) if(hash[i]!=0) vec.push_back(hash[i]);
        
        sort(vec.begin(),vec.end(),greater<int>());
        
        for(int i=1;i<vec.size();i++){
            while(vec[i] && (vec[i]>=vec[i-1])) vec[i]--, res++;
        }
        return res;
    }
};