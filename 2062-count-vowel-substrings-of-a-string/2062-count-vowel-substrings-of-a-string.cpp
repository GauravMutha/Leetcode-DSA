class Solution {
public:
    int countVowelSubstrings(string word) {
        int hash=0,count=0;
        vector<char>vec={'a','e','i','o','u'};
        for(int i=0;i<word.size()-1;i++){
            if(find(vec.begin(),vec.end(),word[i])==vec.end()) continue;
            hash=(1<<(word[i]-'a'));
            for(int j=i+1;j<word.size();j++){
                if(find(vec.begin(),vec.end(),word[j])==vec.end()) break;
                hash|=(1<<(word[j]-'a'));
                if(hash==1065233) count++; 
            }
        }
        return count;
    }
};