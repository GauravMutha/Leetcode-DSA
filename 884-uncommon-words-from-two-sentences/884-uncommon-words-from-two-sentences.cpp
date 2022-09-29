class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>m1;
        vector<string> ans;
        string res="",combined=s1+" "+s2;
        
        for(int i=0;i<combined.size();i++){
            if(combined[i]!=' ') res+=combined[i];
            if((i+1)==combined.size() || combined[i+1]==' ')
                m1[res]++ , res="";
        }
        
        for(auto &[key,value] : m1)
            if(value==1) ans.push_back(key);
        
        return ans;
    }
};