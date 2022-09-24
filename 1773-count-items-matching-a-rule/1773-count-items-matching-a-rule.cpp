class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int j=0,count=0;
        
        if(ruleKey[0]=='t') j=0;
        else if(ruleKey[0]=='c') j=1;
        else j=2;
        
        for(auto vec:items)
            if(vec[j]==ruleValue)count++;
        
        return count;
    }
};