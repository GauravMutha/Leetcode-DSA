class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>hash(26,0);
        vector<int>temp;
        int res=0; 
        bool flag=true;
        for(auto c: chars)
            hash[c-'a']++;
        
        for(auto w :words){
            temp=hash , flag=true;
            for(auto c:w){
                temp[c-'a']--;
                if(temp[c-'a']==-1){
                    flag=false; 
                    break;
                }
            }
            if(flag) res+=(w.size());
        }
        
        return res;
    }
};