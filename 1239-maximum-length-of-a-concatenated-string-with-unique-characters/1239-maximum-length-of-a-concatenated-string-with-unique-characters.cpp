//Iterative 
//Arry of bitsets , DP based
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> results={bitset<26>()};
        int res=0;
        for(auto str : arr){
            bitset<26>currStrHash;
            for(auto ch : str)
                currStrHash.set(ch-'a');
            int charCount=currStrHash.count();
            if(charCount< str.size()) continue; //string itself has duplicates
            
            for(int i=0;i<results.size();i++){
                if((results[i]&currStrHash).any()) continue;
                results.push_back(results[i]|currStrHash);
                res=max(res,(int)results[i].count() + charCount);
            }
        }
        
        return res;
    }
};