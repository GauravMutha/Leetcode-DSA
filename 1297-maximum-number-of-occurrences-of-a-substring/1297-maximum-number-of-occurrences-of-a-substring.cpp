class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int res=0;
        unordered_map<string,int>freq;
          unordered_map<char,int>m;
            for(int l=0,r=0;r<s.size();r++){
                m[s[r]]++;
                if(r-l+1==minSize){
                    if(m.size()<=maxLetters){
                        string temp=s.substr(l,minSize);
                        freq[temp]++;
                    }
                    m[s[l]]--;
                    if(m[s[l]]==0) m.erase(s[l]);
                    l++;
                }
            }
        for (auto it = freq.begin(); it != freq.end(); it++)
            if(it->second>res) res=it->second;
        return res;
    }
};

//sliding window but uses array