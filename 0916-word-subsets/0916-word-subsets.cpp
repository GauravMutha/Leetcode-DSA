class Solution {
public:
    vector<int> mapit(string & word){
        vector<int>m(26,0);
        for(auto &c:word)
            m[c-'a']++;
        return m;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>maxi(26,0);
        vector<string>ans;
        for(auto w : words2){
            vector<int>freq=mapit(w);
            for(int i=0;i<26;i++) 
                maxi[i]=max(freq[i],maxi[i]);
        }
        
        for(auto w : words1){
            vector<int>curr=mapit(w);
            int i=0;
            for(;i<26;i++) if(curr[i]<maxi[i]) break;
            if(i==26) ans.push_back(w);
        }
        return ans;
    }
};