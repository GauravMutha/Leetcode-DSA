class Solution {
public:
    bool issorted(string s1,string s2,unordered_map<char,int>m){
        int i=0;
        for(i=0;i<s1.size() && i<s2.size();i++){
            if(m[s1[i]]==m[s2[i]]) continue;
            else if(m[s1[i]]<m[s2[i]]) return true;
            else return false;
        }
        
        return (i<s1.size() && i>=s2.size()) ? false : true;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>m;
        for(int i=0;i<order.size();i++)
            m[order[i]]=i;
        for(int i=0;i<words.size()-1;i++)
            if(!issorted(words[i],words[i+1],m)) return false;
        return true;
    }
};