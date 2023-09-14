class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict(wordList.begin(),wordList.end());
        queue<string>q;
        int res=1;
        
        q.push(beginWord);
        
        while(q.size()){
            int sz=q.size();
            
            for(int i=0;i<sz;i++){
                
                string word=q.front(); q.pop();
                if(word==endWord) return res;
                dict.erase(word);
                
                for(int j=0;j<word.size();j++){
                    char letter=word[j];
                    for(char c='a';c<='z';c++){
                        word[j]=c;
                        if(dict.find(word)!=dict.end()) q.push(word);
                    }
                    word[j]=letter;
                }
            }
            res++;
        }
        return 0;
    }
};