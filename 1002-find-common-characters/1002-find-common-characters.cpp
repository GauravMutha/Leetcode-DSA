class Solution {
public:
    
    vector<string> commonChars(vector<string>& words) {
        vector<int>ideal(26,0),hash(26,0);
        vector<string>res;
        
        for(auto c : words[0])
            ideal[c-'a']++;
        
        for(int i=1;i<words.size();i++){
            for(auto c: words[i])
                hash[c-'a']++;
            
            for(int i=0;i<26;i++){
                ideal[i]=min(hash[i],ideal[i]);
                hash[i]=0;
            }
        }
        
        
        for(int i=0;i<26;i++){
            int temp=ideal[i];
            while(temp--)
                 res.push_back(string(1,i+97));  
        }
        return res;
    }
};