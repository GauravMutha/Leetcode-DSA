class Solution {
public:
    unordered_map<char,int>m;
    bool issorted(string s1,string s2){
        int i=0;
        for(i=0;i<s1.size() && i<s2.size();i++)
            if(m[s1[i]]!=m[s2[i]]) return m[s1[i]]<m[s2[i]];
        
        return (s1.size()<=s2.size());
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.size();i++)
            m[order[i]]=i;
        for(int i=0;i<words.size()-1;i++)
            if(!issorted(words[i],words[i+1])) return false;
        return true;
    }
};

//TC -->O(nlogn)