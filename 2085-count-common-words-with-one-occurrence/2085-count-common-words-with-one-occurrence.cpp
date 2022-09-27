class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int sz1=words1.size(), sz2=words2.size(),count=0;
        unordered_map<string,int>m1,m2;
        
        for(int i=0;i<max(sz1,sz2);i++){
            if(i<sz1)
                m1[words1[i]]++;
            if(i<sz2)
                m2[words2[i]]++;
        }
        
        for(auto &[key,value] : m1)
            if(value==1 && m2[key]==1) count++;
        
         return count;
        
    }
};