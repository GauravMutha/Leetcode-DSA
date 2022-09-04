class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int n=startWords.size(),m=targetWords.size(),count=0;
        unordered_set<int>sv;
        
        for(int i=0;i<n;i++){
            int num=0;
            for(auto ch :startWords[i])
                num|=(1<<(ch-'a'));
            sv.insert(num);
        }
        
        for(int i=0;i<m;i++){
            int bin=0;
            for(auto ch :targetWords[i])
                bin|=(1<<(ch-'a'));
            for(auto ch:targetWords[i]){
                int temp=bin^(1<<(ch-'a'));
                if(sv.find(temp)!=sv.end()){count++;break;}
                temp=bin^(1<<(ch-'a'));
            }
        }
        return count;
    }
};