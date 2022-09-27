class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int count=0;
        unordered_map<string,int>m1;
        
        for(auto w1 : words1)
            m1[w1]++;
        
        for(auto w2 : words2)
            if(m1[w2] <2) m1[w2]--;
        
        for(auto it1=m1.begin();it1!=m1.end();it1++)
            if((it1->second)==0) count++;
        
        return count;
        
    }
};

//using only one map