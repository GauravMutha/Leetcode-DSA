class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count=0;
        
        for(int i=0;i<items.size();i++){
            if(ruleKey[0]=='t' && items[i][0]==ruleValue) count++;
            else if(ruleKey[0]=='c' && items[i][1]==ruleValue) count++;
            else if(ruleKey[0]=='n' && items[i][2]==ruleValue) count++;
        }
        
        return count;
    }
};