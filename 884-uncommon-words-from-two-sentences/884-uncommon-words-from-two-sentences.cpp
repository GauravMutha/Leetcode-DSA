class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>m1;
        vector<string> ans;
        string res="";
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=' ') res+=s1[i];
            if((i+1)==s1.size() || s1[i+1]==' ')
                m1[res]++ , res="";
        }
        
        for(int i=0;i<s2.size();i++){
            if(s2[i]!=' ') res+=s2[i];
            if((i+1)==s2.size() || s2[i+1]==' ')
                m1[res]++,res="" ;
        }
        
        for(auto &[key,value] : m1)
            if(value==1) ans.push_back(key);
        
        return ans;
    }
};