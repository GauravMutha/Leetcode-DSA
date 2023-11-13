class Solution {
public:
    bool isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
    }
    string sortVowels(string s) {
        map<char,int>m;
        
        for(auto c : s) if(isVowel(c)) m[c]++;
        
        auto it=m.begin();
        for(int i=0;i<s.size() && it!=m.end();i++){ 
            if(isVowel(s[i])==false) continue;
            
            s[i]=it->first;
            it->second--;
            if(it->second==0) it++;
        }
        return s;
    }
};